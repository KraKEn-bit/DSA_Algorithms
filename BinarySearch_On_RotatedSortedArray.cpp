//Suppose and array: 4 5 6 7 0 1 2
//It is a rotated sorted array meaning half of it is sorted. In this case the binary search will have 4 conditions meaning at first it will find
//If the sorted part is in right side or left sde by checking start and mid's element or mid and end's element. Then it checks
//if the target is between mid and start or mid and end. Then checks if that part of array is sorted or not. If sorted then apply the left and right
//part's normal binary search by comparing array[mid] with target.
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int target;
    cout<<"Enter a target value: ";
    cin>>target;
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(array[mid]==target){
            cout<<"The index is: "<<mid;
            return 0;
        }
        else if(array[start]<=array[mid]){
            if(array[start]<=target && target<=array[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(array[mid]<=target && target<=array[end]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    cout << "The target value was not found in the array: "<<-1; 
    return 0;
}