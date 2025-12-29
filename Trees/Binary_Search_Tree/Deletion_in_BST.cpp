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
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root,int val){
    Node* newNode = new Node(val);
    if(root==NULL){
        return newNode;
    }

    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else if(val>root->data){
        root->right = insert(root->right,val);
    }
    else{
        return root;
    }
}

Node* getinOrderSuccessor(Node* root){  //Left Most Node in Right SubTree
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }

    if(val<root->data){
        root->left = delNode(root->left,val);
    }
    else if(val>root->data){
        root->right = delNode(root->right,val);
    }
    else{
        if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right ==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* inOrderSuccessor = getinOrderSuccessor(root->right);
            root->data = inOrderSuccessor->data;
            root->right = delNode(root->right,inOrderSuccessor->data);
        }
    }
}

Node* buildBST(vector<int>arr){
    Node* root = NULL;

    for(int x:arr){
        root = insert(root,x);
    }
    return root;
}

void inOrder(Node* root){
    if(root==NULL){
        return ;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}



int main(){
    vector<int> arr = {3,2,1,4,5,6};

    Node* root = buildBST(arr);

    cout<<"Inorder Traversal: "<<endl;
    inOrder(root);
    cout<<endl;

    delNode(root,5);

    cout<<"Inorder Traversal: "<<endl;
    inOrder(root);
    cout<<endl;

}