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
    int CurrSum=0,maxSum=INT_MIN;
    for(int i=0;i<n;i++){
        CurrSum+=array[i];
        maxSum=max(CurrSum,maxSum);
        if(CurrSum<0){
            CurrSum=0;
        }
    }
    cout<<"Maximum sub array sum is: "<<maxSum;
    return 0;
}

//Explanation:
// It is like big(+) + small(-) = +
//             big(-) + small(+) = -
// So if result = (-) comes then current_sum will revert to '0' again it won't count negative values.