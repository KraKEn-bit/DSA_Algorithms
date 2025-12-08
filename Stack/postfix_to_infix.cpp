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

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        } 
        else if (isOperator(c)) {
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();

            string exp = "(" + a + c + b + ")";
            st.push(exp);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cin>>postfix;
    cout << "Infix: " << postfixToInfix(postfix) << endl;
    return 0;
}



// isalnum() is a C/C++ built-in function that checks whether a character is:

// a letter (a–z or A–Z)

// a digit (0–9)