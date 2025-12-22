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

    stack<int> st;
    vector<int> prev_smaller_el(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && array[i]<=st.top()){
            st.pop();
        }
        if(st.empty()){
            prev_smaller_el[i]=-1;
        }
        else{
            prev_smaller_el[i] = st.top();
        }
        st.push(array[i]);
    }

    for(int x : prev_smaller_el){
        cout<<x<<" ";
    }
}