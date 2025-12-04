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

    stack<string> st;

    string str;
    cin>>str;

    string infx;
    int len = str.length();

    for(int i=len-1;i>=0;i--){
        if((str[i]>='A' && str[i]<='Z') ||
            (str[i]>='a' && str[i]<='z') ||
            (str[i]>='0' && str[i]<='9')){
                string op(1,str[i]);
                st.push(op);
            }
            else{
                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                infx = '(' + t2 + str[i] + t1 + ')';

                st.push(infx);
            }
    }
    cout<<st.top();
}