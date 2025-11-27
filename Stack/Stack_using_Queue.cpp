#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>

using namespace std;


queue<int> q;

void push(int element){
    q.push(element);
    for(int i=1;i<q.size();i++){
        q.push(q.front());
        q.pop();
    }
}

void pop(){
    if(q.empty()){
        cout << "Stack is empty!" << endl;
        return;
    }
    q.pop();
}   

int front(){
     if(q.empty()){
        cout << "Stack is empty!" << endl;
     }
     return q.front();
}


bool empty(){
    return q.empty();
}

int main(){
    push(10);
    push(20);
    push(30);

    cout << "Top: " << front() << endl; 
    pop();
    cout << "Top: " << front() << endl; 
    pop();
    cout << "Top: " << front() << endl; 

    return 0;
}