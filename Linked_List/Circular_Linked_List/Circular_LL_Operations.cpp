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

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Clist{
    Node* head;
    Node* tail;

    public: 

    Clist(){
        head = tail = NULL;
    }

    void Insert_at_head(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head = tail = newNode;
            newNode->next = head;
        }
        else{
            newNode->next = head;
            head = newNode;
            tail ->next = head;
        }
    }

    void Insert_at_tail(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = tail = newNode;
            newNode->next = head;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            
        }
    }


    void delete_head(){
        if(head==NULL){
            cout<<"List is empty!";
            return;
        }
        else if(head==tail){
            delete head;
            head = tail = NULL;
        }
        else{
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void delete_tail(){
        if(tail==NULL){
            cout<<"List is empty!";
            return;
        }
        else if(head == tail){
            delete tail;
            head = tail = NULL; 
        }
        else{
            Node* temp = tail;
            Node* prev = head;
            while(prev->next!=tail){
                prev = prev->next;
            }

            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void print(){
        Node* temp = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        
        while(temp!=head){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Clist cll;

    cll.Insert_at_head(3);
    cll.Insert_at_head(4);
    cll.Insert_at_head(2);

    cll.print();

    cll.Insert_at_tail(10);
    cll.Insert_at_tail(9);
    cll.Insert_at_tail(12);

    cll.print();

    cll.delete_head();
    cll.delete_head();

    cll.print();

    cll.delete_tail();
    cll.delete_tail();

    cll.print();

}