#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    vector<int>preffix(n);
    preffix[0]=1;
    for(int i=1;i<n;i++){
        preffix[i]=preffix[i-1]*array[i-1];
    }
    vector<int>suffix(n);
    suffix[n-1]=1;
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*array[i+1];
    }
    vector<int>answer(n);
    for(int i=0;i<n;i++){
        answer[i]=suffix[i]*preffix[i];
    }
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}

//Finding preffix of a number:
// vector<int>preffix(n);
// preffix[0]=1;
// for(int i=1;i<n;i++){
//     preffix[i]=preffix[i-1]*array[i-1];
// }


//Finding suffix of a number: 
// vector<int>suffix(n);
// suffix[n-1]=1;
// for(int i=n-2;i>=0;i--){
//     suffix[i]=suffix[i+1]*array[i+1];
// }



// Here I took a suffix and preffix to track the multiplications of numbers coming after and before ith element.
//  If I approach this way from the left numbers upto that ith element, it is refferring to preffix else it is refferring to suffix intializing
//  the first for preffix and last element for suffix with number=1. 
//  Then multiply those two and store them and then print all together.


// This code's TC= O(4n)=O(n)