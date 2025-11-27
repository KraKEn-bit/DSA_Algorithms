#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int q[10];
int start=-1,rear=-1,currSize=0;
int maxSize=10;

void push(int element){
    if(currSize==maxSize){
        cout<<"Queue is FULL!"<<endl;
    }
    else{
        if(start==-1){
            start=0;
        }
        rear=(rear+1)%maxSize;
        q[rear]=element;
        currSize++;
    }
}

void pop(){
    if(currSize==0){
        cout<<"Queue is Empty!"<<endl;
        return;
    }

        start = (start+1)%maxSize;
        currSize--;

    if(currSize==0){
        start=-1;
        rear=-1;
    }
}

int top(){
    if(currSize==0){
        cout<<"Queue is Empty!"<<endl;
    }
    else{
        return q[start];
    }
}

int size(){
    return currSize;
}

bool isEmpty(){
    if(currSize==0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    push(5);
    push(7);
    push(10);

    pop();
    pop();

    push(13);
    push(14);

    pop();
    
    for(int i=0; i<currSize; i++){
        cout << q[(start + i) % maxSize] << " ";
    }
    cout<<endl;
    cout<<"Top element is: "<<top();
}   