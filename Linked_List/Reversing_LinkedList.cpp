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

        void reverselist(){
            Node* temp = head;
            vector<int> arr;
            while(temp!=NULL){
                arr.push_back(temp->data);
                temp = temp->next;
            }
            temp = head;
            for(int i = arr.size()-1;i>=0;i--){
                temp->data = arr[i];
                temp = temp->next;
            }
        }

};

int main(){
    List ll;

    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(10);
    ll.push_back(13);
    ll.push_back(16);

    ll.print();

    cout<<"Reversed List: "<<endl;
    ll.reverselist();
    ll.print();
}