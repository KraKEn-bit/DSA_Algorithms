//Peak index can be achieved only then when half of the array is ascending and other half is descending. Only one of the elements will be a peak element.
//and to check that check the element before it (element-1) and after it (element+1) [here element is mid] . If the element is bigger than both then it's
//a Peak element.


//There is an alternative approach to this problem. Where you only find the maximum element of the array and return the index. But that aproach's
//TC will be O(n) where binary search will give O(logn) TC!!!
 

//***  [If a portion of an array is sorted in any order binary search can be applied on that]

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
    int start=1,end=n-2;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(array[mid-1]<=array[mid] && array[mid]>=array[mid+1]){
            cout<<mid;
            return 0;
        }
        else if(array[mid-1]<array[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    cout<<-1;
    return 0;
}