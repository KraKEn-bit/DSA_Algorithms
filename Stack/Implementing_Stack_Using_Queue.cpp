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

queue<int>q1;
queue<int>q2;

void push(int element){
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    
    q1.push(element);

    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}


int pop(){
    int ans=q1.front();
    q1.pop();
    return ans;
}


int front(){
    return q1.front();
}

bool isEmpty(){
    return q1.front();
}

int main(){
    push(7);
    push(9);
    push(3);

    pop();

    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
}