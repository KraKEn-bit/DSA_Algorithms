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
        data =value;
        next=NULL;
    }
};


class list{
   
    Node* head;
    Node* tail;

    public:
    list(){
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

        void sort_ll(){
            vector<int>array;
            Node* temp = head;

            while(temp!=NULL){
                array.push_back(temp->data);
                temp=temp->next;
            }
            sort(array.begin(),array.end());
            
            temp = head;
            int i=0;
            while(temp!=NULL){
                temp->data = array[i];
                temp = temp->next;
                i++;
            }
        }
};


int main(){
    list l1;
    list l2;
    list total_l;

    int n;
    cin>>n;

    vector<int>array1(n);

    for(int i=0;i<n;i++){
        cin>>array1[i];
        l1.push_back(array1[i]);
        total_l.push_back(array1[i]);
    }

    vector<int>array2(n);
    for(int i=0;i<n;i++){
        cin>>array2[i];
        l2.push_back(array2[i]);
        total_l.push_back(array2[i]);
    }

    total_l.sort_ll();
    total_l.print();
}