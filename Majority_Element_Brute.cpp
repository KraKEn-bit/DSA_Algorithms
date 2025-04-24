#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int count,found=0;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(array[i]==array[j]){
                count++;
            }
        }
        if(count > n / 2){
            cout<<"Majority element is: "<<array[i];
            found=1;
            break;
        }
        else{
            cout<<"No majority elemnent found";
            break;
        }
    }
    return 0;
}