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

    int sum=0;
    int mod = (int)(1e9 + 7);
    for(int i=0;i<n;i++){
        int min_el = INT_MAX;
        for(int j=i;j<n;j++){
            min_el = min(array[j],min_el);
            sum= (sum+min_el)%mod;
        }
    }
    cout<<sum;
}