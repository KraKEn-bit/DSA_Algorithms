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

stack<char> st;

int main(){
    string str;
    getline(cin,str);

    int len =str.length();
    
    bool seq_broke = false;

    for(int i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='{' || str[i] == '['){
            st.push(str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(st.empty()){
                seq_broke=true;
                break;
            }

            char top = st.top();
            st.pop();

            if((str[i] == ')' && top!='(') || 
                (str[i] == '}' && top != '{') ||
                (str[i] == ']' && top != '[')){
                    seq_broke = true;
                    break;
            }
        }
    }   

    if(!st.empty()){
        seq_broke=true;
    }

    if(!seq_broke){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
