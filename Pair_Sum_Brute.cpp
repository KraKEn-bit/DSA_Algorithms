#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n,target;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter target value: ";
    cin>>target;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    sort(array.begin(),array.end());
    vector<int>result;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(array[i]+array[j]==target){
                result.push_back(array[i]);
                result.push_back(array[j]);
            }
        }
    }
    cout<<"The desired pair sum is: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}