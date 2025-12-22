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

    int min_el, max_el;
    int min_res,max_res;
    int res=0 , minus;


    for(int i=0;i<n;i++){
        min_el = INT_MAX;
        max_el = INT_MIN;
        minus = 0;
        //cout<<arr[i]<<endl;
        for(int j=i;j<n;j++){
            //cout<<arr[j]<<" ";
            min_el = min(min_el,arr[j]);
            max_el = max(max_el,arr[j]);
            minus = max_el - min_el;
            res+=minus;
        }
        //cout<<endl;
    }
    cout<<res;
}