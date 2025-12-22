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

vector<int> next_greater_element(vector<int>& arr,int n){
    stack<int>st;
    vector<int> nge(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]>st.top()){
            st.pop();
        }
        if(st.empty()){
            nge[i]=-1;
        }
        else{
            nge[i]=st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

vector<int> prev_greater_element(vector<int>& arr,int n){
    stack<int>st;
    vector<int> pge(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>st.top()){
            st.pop();
        }
        if(st.empty()){
            pge[i]=-1;
        }
        else{
            pge[i]=st.top();
        }
        st.push(arr[i]);
    }
    return pge;
}


int main(){

    int n;
    cin>>n;

    vector<int>array(n);

    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    vector<int> nge = next_greater_element(array,n);
    vector<int> pge = prev_greater_element(array,n);

    long long left , right;
    long long total=0;
    
    for(int i=0;i<n;i++){
        left = i - pge[i];
        right = nge[i]-i;
        total = total+ (long long)(left*right*array[i]);
    }
    cout<<total;
}