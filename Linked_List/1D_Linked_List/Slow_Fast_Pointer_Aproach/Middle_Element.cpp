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

        
        void print_middle(){
            Node* Slow=head;
            Node* Fast = head;

            if(head == NULL){
                cout << "List is empty!" << endl;
                return;
            
            }
            while(Slow!=NULL && Fast->next!=NULL){
                Slow = Slow->next;
                Fast = Fast->next->next;
            }
            Node* temp = Slow;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
int main(){
    List ll;
    int n;
    cin>>n;

    vector<int>array(n);

    for(int i=0;i<n;i++){
        cin>>array[i];
        ll.push_back(array[i]);
    }
    ll.print_middle();
}