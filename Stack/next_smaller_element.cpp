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

    stack<int>st;
    vector<int>next_small_el(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<st.top()){
            st.pop();
        }
        if(st.empty()){
            next_small_el[i] = -1;
        }
        else{
            next_small_el[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(int x : next_small_el){
        cout<<x<<" ";
    }
}