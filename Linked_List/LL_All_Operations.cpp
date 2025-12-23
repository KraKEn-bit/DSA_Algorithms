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
                return;
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
                return;
            }
            if(head==tail){
                delete head;
                head=tail=NULL;
                return;
            }
            Node* temp;
            temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            temp->next = NULL;
        }

        void insert(int value,int pos){
            Node* newNode = new Node(value);
            
            Node* temp;
            temp = head;

            if(pos<0){
                cout<<"Invalid Position!"<<endl;
                return;
            }
            if(pos==0){
                push_front(value);
                return; 
            }
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        void delete_value(int value,int pos){
            Node* temp;
            temp = head;
            if(pos<0){
                cout<<"Invalid Position!"<<endl;
                return;
            }
            if(pos==0){
                pop_front();
                return;
            }
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }
            Node* temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = NULL;
            delete temp1;
        }
        
        void search(int key){
            Node* temp=head;
            int index = 0;

            while(temp!=NULL){
                if(temp->data == key){
                    cout<<"Searched value's Index: "<<index<<endl;
                }
                temp = temp->next;
                index++;
            }
            // cout<<"No Index Found!"<<endl;
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
    ll.insert(59,0);

    ll.print();

    ll.search(20);

    ll.delete_value(59,0);
    ll.delete_value(4,1);

    ll.print();
}