#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int st[10];
int topindx=-1;

void push(int element){
    if(topindx==9){
        cout<<"Stack is Full! "<<endl;
        return;
    }
    else{
        topindx++;
        st[topindx]=element;
    }
}

void pop(){
    if(topindx==-1){
        cout<<"Stack is empty!"<<endl;
        return;
    }
    else{
        topindx--;
    }
}

int top(){
    if(topindx==-1){
        cout<<"Stack is empty!"<<endl;
        return;
    }
    else{
        return st[topindx];
    }
}

int size(){
    return topindx+1;
}

bool isEmpty(){
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(){
    if(size()){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    push(2);
    push(5);
    push(7);

    // for(int i=0;i<size();i++){
    //     cout<<st[i]<<" ";
    // }

    cout<<"Top Element: "<<top()<<endl;

    pop();
    
    cout<<"Top Element: "<<top()<<endl;

    push(13);
    push(15);

    cout<<"Size: "<<size();
}