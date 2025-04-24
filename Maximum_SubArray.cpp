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
    vector<int>result;
    int res;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            res=0;
            for(int k=i;k<j;k++){
                res+=array[k];
            }
            result.push_back(res);  
        }
    }
    int max=INT_MIN;
    for(int i=0;i<result.size();i++){
        if(result[i]>max){
            max=result[i];
        }
    }
    cout<<"The maximum subarray sum is: "<<max;
    return 0;
}

//For more Efficiency:
// int CurrSum,maxSum=INT_MIN;
// for(int i=0;i<n;i++){
//     CurrSum=0;
//     for(int j=i;j<n;j++){
//         CurrSum+=array[j];
//         maxSum=max(CurrSum,maxSum);
//     }
// }
// cout<<"The maximum subarray sum is:"<<maxSum;