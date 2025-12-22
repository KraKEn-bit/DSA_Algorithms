// Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
// Output: [-6,2,4]


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
    stack<int>st;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    stack<int>st2;

    for(int i=0;i<n;i++){
        int dest = 0;
        while(!st.empty() && st.top()>0 && arr[i]<0){
            if(abs(st.top())<abs(arr[i])){
                st.pop();
                continue;
            }
            else if(abs(st.top())==abs(arr[i])){
                st.pop();
                dest = 1;
                break;
            }
            else{
                dest=1;
                break;
            }
    
        }
        if(!dest){
            st.push(arr[i]);
        }
    }

    vector<int>ans;
    for(int i=st.size()-1;i>=0;i--){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

