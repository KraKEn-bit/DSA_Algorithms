//This problem can be solved by using xor Bitwise operator.


// But as 2 sides of the peak are sorted in an order We can use binary search here.
//For this we have check at which side the single eelment will be. To check this we need to find the mid at first and if the mid%2==0 then left and
//right both sides have even number of elements and if not both sides have odd number of elements. If even then the previous number of mid will be equal
//and that's why the end=mid-1 else start start=mid+1. On the other hand if Odd then start =mid+1 else end=mid-1;And the edge cases will be for first and
//last index which will tell us that if the the element  is the single element or not.!

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){

       // int res = 0;
        // for (int i = 0; i < n; i++) {
        //     res ^= nums[i];
        // }
        // return res;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    if(n==1){
        cout<<array[0];
        return 0;
    }
    int start=1,end=n-2;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid==0 && array[mid]!=array[mid+1]){
            cout<<mid;
            return 0;
        }
        if(mid==n-1 && array[n-2]!=array[mid]){
            cout<<mid;
            return 0;
        }
        if(array[mid-1]!=array[mid] && array[mid+1]!=array[mid]){
            cout<<mid;
            return 0;
        }
        else if(mid%2==0){
            if(array[mid-1]==array[mid]){
            end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(array[mid-1]==array[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
}
    cout<<-1;
    return 0;
}