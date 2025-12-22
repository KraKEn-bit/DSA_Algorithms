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
    
    vector<int>array(n);

    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int res =0 ;
    for(int i=0;i<n;i++){
         int leftmax = INT_MIN,rightmax = INT_MIN;
            for(int j=i;j>=0;j--){
                leftmax = max(leftmax,array[j]);
            }
            for(int k=i;k<n;k++){
                rightmax = max(rightmax,array[k]);
            }

            res += min(leftmax,rightmax) - array[i];
        }
        cout<<res;
}