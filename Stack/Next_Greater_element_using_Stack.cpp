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
    stack<int> st1,st2;
    vector<int>array;

    int numb;
    while(true){
        cin>>numb;
        if(numb==-1){
            break;
        }
        array.push_back(numb);
        st1.push(numb);
     }

    int n = array.size();

    for(int i=n-1;i>=0;i--){
        if(array[i]==st1.top()){
            int current = st1.top();
            int start = i+1;
            st1.pop();
            if(current == array[n-1]){
                st2.push(-1);
            }
            for(int j=start;j<n;j++){
                if(current<array[j]){
                    st2.push(array[j]);
                    break;
                }
                else{
                    continue;
                }
                st2.push(-1);
            }
        }
    }

    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
}