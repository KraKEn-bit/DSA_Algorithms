//This problem is similar to the book allocation,painter's partition problem.
//Here I need to find the minimum distance and latgest distance for the range. Here minimum will always be 1 which is start value. And max will be 
//the distance between the intitial cow and the furthest cow situated = maxarray-minarray = end value (For binary search range)

//After finding the range now I have to check where to apply Left and right BS. To do that 1st I have to find the mid. The values between start and end
//are indicating the distances between Cow-1 and cow-2....Cow-2 and cow-3. So i have to find the minimum distance possible. So suppose the mid=4 which 
//is the distance between cow-1(at 4) and cow-2(at 8) Now to assume mid as the minimum we have find a distance between cow-3 and others such that mid=4
//will be minimum value. But that's not possible for array=[1,2,8,4,9] . So as it's not possible the values after it will have the same result. So
//we should do Left BS else Right BS.

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

//For this function it checks if the mid value=maxAllowedDis is possible or not. For this we need to sort the array. Then put the 3 cows according 
//to the array position on the start to end (numberline).And compare the distances between Cow-1 and cow-2. If the distance is
//greater than maxAllowedDis=mid,thenwe increase the cow value to 2. Now at that index cow-2 sits. Thus we got the distance between cow-1 and cow-2.
//Then update the distance to that array.and again checks if cow-3 can be placed or not by finding another mid and so on.

int isvalid(vector<int>& arr, int n, int c, int maxAllowedDis){
    int cow=1,distance=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-distance>=maxAllowedDis){
            cow++;
            distance=arr[i];
        }
    }
       if(cow==c){
            return true;
        }
    else{
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
    int c;
    cout<<"Enter number of cows: ";
    cin>>c;
    sort(array.begin(), array.end());
    int start=1,end=array[n-1]-array[0];
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isvalid(array,n,c,mid)){
            start=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;
        }
    }
    cout<<ans;
    return 0;
}