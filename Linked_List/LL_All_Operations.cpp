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


class List{
    Node* head;
    Node* tail;

    public:
        List(){
            head=tail=NULL;
        }

        void push_front(int value){
            Node* newNode = new Node(value);
            
            if(head==NULL){
                head=tail= newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
        }

        void push_back(int value){
            Node* newNode = new Node(value);

            if(tail==NULL){
                head=tail=newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void print(){
             Node* temp = head;
             while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
             }   
             cout<<endl;
        }

        void pop_front(){
            if(head==NULL){
                cout<<"List is empty!";
            }
            Node* temp;
            temp=head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        void pop_back(){
            if(head==NULL){
                cout<<"List is empty!";
            }

            Node* temp;
            temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            //temp = tail;
            temp->next = NULL;
            delete temp;
            temp = tail;
        }

        void insert(int value,int pos){
            Node* newNode = new Node(value);
            
            Node* temp;
            temp = head;

            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(1);
    ll.push_front(10);
    ll.push_back(13);
    ll.push_back(16);
 
    ll.print();

    ll.pop_front();
    ll.pop_back();
    ll.pop_front();

    ll.print();

    ll.insert(5,2);
    ll.insert(20,3);
    
    ll.print();

}