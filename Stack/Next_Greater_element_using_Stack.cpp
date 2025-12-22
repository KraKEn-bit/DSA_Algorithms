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

    stack<int> st;
    vector<int>array(n);

    array.resize(n); 
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

     vector<int>next_greater_el(n);

     for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=array[i]){
            st.pop();
        }
        if(st.empty()){
            next_greater_el[i] = -1;
        }
        else{
            next_greater_el[i] = st.top();
        }
        st.push(array[i]);
     }

     for(int x:next_greater_el){
        cout<<x<<" ";
     }


}