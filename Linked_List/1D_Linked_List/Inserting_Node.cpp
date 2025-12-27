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

class list{
    private:
        Node* head;
        Node* tail;
    public:
        list(){
            head=tail=NULL;
        }

        void push_front(int value){
            Node* newNode = new Node(value);

            if(head==NULL){
                head=tail=newNode;
            }
            else{
                newNode -> next = head;
                head = newNode;
            }
        }

        void push_back(int value){
            Node* newNode = new Node(value);
            if(head==NULL){
                head=tail=newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
                newNode->next=NULL;
            }
        }   

        void insert(int value,int pos){
            Node* newNode = new Node(value);
            Node* temp=head;

            for(int i=0;i<pos-1;i++){
                temp=temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void print(){
            Node* temp;
            temp = head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){
    list ll;
    
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(1);
    ll.push_front(10);
    
    ll.print();

    ll.push_back(21);
    ll.push_back(12);

    ll.print();

    ll.insert(5,2);
    ll.insert(20,3);

    ll.print();
}