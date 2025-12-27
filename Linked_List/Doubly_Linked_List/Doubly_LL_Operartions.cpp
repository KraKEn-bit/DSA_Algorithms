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

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};


class Dlist{
    Node* head;
    Node* tail;

    public:

    Dlist(){
        head=tail=NULL;
    }

    void push_front(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout<<"List is empty!";
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
    }


    void pop_back(){
        if(head==NULL){
            cout<<"List is empty!";
            return;
        }
        else{
            Node* temp = tail;
            tail = tail->prev;

            if(tail!=NULL){
                tail->next = NULL;
            }

            temp->prev = NULL;
            delete temp;
        }
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


int main(){
    Dlist dll;

    dll.push_front(3);
    dll.push_front(5);
    dll.push_front(4);

    dll.print();

    dll.push_back(10);
    dll.push_back(12);
    dll.push_back(9);

    dll.print();

    dll.pop_front();
    dll.pop_front();

    dll.print();

    dll.pop_back();
    dll.pop_back();

    dll.print();
}