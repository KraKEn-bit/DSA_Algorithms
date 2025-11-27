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

stack<int>st1;
stack<int>st2;

void push(int element){
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }

    st1.push(element);

    while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
    }
}

int pop(){
    int ans = st1.top();
    st1.pop();
    return ans;
}

int front(){
    return st1.top();
}

bool isEmpty(){
    return st1.empty();
}

int main(){
    push(6);
    push(8);
    push(3);

    pop();
    
    while(!st1.empty()){
        cout << st1.top() << " ";
        st1.pop();
    }

}

