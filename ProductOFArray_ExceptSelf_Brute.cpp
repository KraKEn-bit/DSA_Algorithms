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
    vector<int>answer(n);
    for(int i=0;i<n;i++){
        int res=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                res *= array[j];
            }
        }
        //answer.push_back(res);
        answer[i]=res;
    }
    for(int i=0;i<n;i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}

// Here, vector<int> answer(n); creates a vector of size n, already filled with zeros (default-initialized).
// When you do answer[i] = res;, you are correctly filling the i-th index.
// Now, if you instead use answer.push_back(res);, you are not replacing elements, you are adding new elements at the end of the answer vector.
// Since answer already had n zeros initially, you now have n zeros + n correct values,

// For this part:
// for(int i=0;i<n;i++){
//     cout<<answer[i]<<" ";
// }
// you are only printing the first n elements, which are still the old zeros!
// That's why you see 0 0 0 0.



// This approach takes O(n^2) which will exceed it's constraints if mentioned.