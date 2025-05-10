#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int target;
    cout<<"Enter target value: ";
    cin>>target;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    sort(array.begin(),array.end());
    int start=0,end=n-1;
    int res;
    cout<<"The elements are: ";
    while(start<end){
        res=array[start]+array[end];
        if(res>target){
            end--;
        }
        else if(res<target){
            start++;
        }
        else{
            cout<<array[start]<<" "<<array[end];
            break;
        }
    }
    return 0;
}