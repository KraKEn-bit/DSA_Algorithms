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

        bool isCircular(){
            Node* slow = head;
            Node* fast = head;

            while(fast!=NULL && fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast){
                    Node* temp = head;
                    while(temp!=slow){
                        temp=temp->next;
                        slow=slow->next;
                    }
                    return temp;
                }
            }
            return false;
        }
        
        //If I didn't make a custom cycle it would give false everytime. But in LeetCode's case this part's already created 
        //so we don't need it there
        void makeCycle(int pos) {
            if (pos < 0) return; 

            Node* temp = head;
            Node* target = head;
            for (int i = 0; i < pos; i++) {
                target = target->next;
            }
            while (temp->next != NULL) temp = temp->next;
                temp->next = target;
            }
};


int main(){
    list ll;
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        ll.push_back(array[i]);
    }

    int pos;
    cin >> pos; 
    ll.makeCycle(pos);

    if (ll.isCircular()) {
        cout << "List has a cycle. That is from "<<ll.isCircular()<< endl;

    } 
    else {
        cout << "List is not circular" << endl;
    }

    return 0;
}
