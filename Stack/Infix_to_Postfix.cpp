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


int precedence(char ch){
    if(ch=='*' || ch=='/'){
        return 2;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    stack<char>st;
    vector<char>ans;

    string str;
    getline(cin,str);

    int len = str.length();

    for(int i=0;i<len;i++){
        if((str[i]>='A' && str[i]<='Z') || 
           (str[i]>='a' && str[i]<='z') ||
           (str[i]>='0' && str[i]<='9')){
            ans.push_back(str[i]);
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && st.top()!='(' &&
                  precedence(st.top()) >= precedence(str[i])){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}