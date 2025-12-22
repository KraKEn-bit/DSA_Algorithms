#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;

    while (left < right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax){
                leftMax = arr[left];
            }
            else{
                res += leftMax - arr[left];
            }
            left++;
        } 
        else {
            if (arr[right] >= rightMax){
                rightMax = arr[right];
            }
            else{
                res += rightMax - arr[right];
            }
            right--;
        }
    }

    cout<<res;
}