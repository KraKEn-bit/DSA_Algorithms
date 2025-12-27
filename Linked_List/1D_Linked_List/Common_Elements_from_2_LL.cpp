#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_map>

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
public:
    Node* head;
    Node* tail;

    List(){
        head = tail = NULL;
    }

    void push_front(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }


    void push_back(int value){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

Node* getIntersection(Node* headA, Node* headB){

    unordered_map<Node*, int> mp;

    Node* tempA = headA;
    while(tempA != NULL){
        mp[tempA] = 1;
        tempA = tempA->next;
    }

    Node* tempB = headB;
    while(tempB != NULL){
        if(mp.find(tempB) != mp.end()){
            return tempB; 
        }
        tempB = tempB->next;
    }

    return NULL;
}

    void printCommon(Node* headA, Node* headB){

    unordered_map<Node*, int> mp;

    Node* tempA = headA;
    while(tempA != NULL){
        mp[tempA] = 1;
        tempA = tempA->next;
    }

    Node* tempB = headB;
    while(tempB != NULL){
        if(mp.find(tempB) != mp.end()){
            cout << tempB->data << " ";
        }
        tempB = tempB->next;
    }

    cout << endl;
    }

int main(){
    List A, B;

    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);


    B.push_back(9);
    B.push_back(8);

    B.tail->next = A.head->next->next; 

    cout << "List A: ";
    A.print();

    cout << "List B: ";
    B.print();

    Node* inter = getIntersection(A.head, B.head);

    if(inter != NULL){
        cout << "Intersection at node with value: " << inter->data << endl;
    }
    else{
        cout << "No intersection found" << endl;
    }

    cout << "Common elements: ";
    printCommon(A.head, B.head);

}
