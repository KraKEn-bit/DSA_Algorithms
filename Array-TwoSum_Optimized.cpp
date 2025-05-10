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
    sort(array.begin(),array.end());
    int target;
    cout<<"Enter a target: ";
    cin>>target;
    cout<<"The indexes are: ";
    int start=0,end=n-1;
    while(start<end){
        if(array[start]+array[end]==target){
            cout<<start<<" "<<end;
            break;
        }
        else if(array[start]+array[end]>target){
            end--;
        }
        else{
            start++;
        }
    }
    return -1;
}