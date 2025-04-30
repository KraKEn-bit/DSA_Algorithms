#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int isvalid(int arr[],int maxAllowedtime,int n,int k){
    int painter=1,time=0;
    for(int i=0;i<n;i++){
        if(time+arr[i]<=maxAllowedtime){
            time+=arr[i];
        }
        else{
            painter++;
            time=arr[i];
        }
    }
    if(painter<=k){
        return true;
    }
    if(painter>k){
        return false;
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int k;
    cout<<"Enter number of painters: ";
    cin>>k;
    if(k>n){
        cout<<-1;
        return 0;
    }
    int min=0;
    for(int i=0;i<n;i++){
        min=max(min,array[i]);
    }
    int res=0;
    for(int i=0;i<n;i++){
        res+=array[i];
    }
    //Should I use start=0 or start=max(array[i])?
    // this is critical for correct and efficient binary search in both Book Allocation and Painter’s Partition problems.
    // ✅ You should set:
    // low = max(array[i]) – the largest single element (since at least one painter/student must handle this much).
    // high = sum(array) – the total of all elements (one painter/student does all the work).

    // ❌ Do NOT set low = 0
    // Because:
    // It may lead to invalid "answers" that aren't feasible (e.g., assigning fewer pages than the maximum single book, which is impossible).
    // It causes unnecessary binary search iterations.
    int ans=-1,start=min,end=res;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isvalid(&array[0],mid,n,k)){
            end=mid-1;
            ans=mid;
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
//Similar to Book Allocation problem. See the explanation on that