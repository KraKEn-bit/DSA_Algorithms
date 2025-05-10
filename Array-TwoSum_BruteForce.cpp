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
    int target;
    cout<<"Enter a target: ";
    cin>>target;
    cout<<"The indexes are: ";
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]+array[j]==target){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}