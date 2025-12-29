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
    if(root == NULL){
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

Node* buildBST(vector<int>arr){
    Node* root = NULL;

    for(int x:arr){
        root = insert(root,x);
    }
    return root;
}


bool searchBST(Node* root,int val){
    if(root==NULL){
        return false;
    }

    if(root->data==val){
        return true;    
    }
    else if(val<root->data){
        return searchBST(root->left,val);
    }
    else if(val>root->data){
        return searchBST(root->right,val);
    }
    else{
        return false;
    }
}


void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}



int main(){
    vector<int> array = {3,2,1,5,4,6};

    Node* root = buildBST(array);
    cout<<"InOrder Output: "<<endl;
    inorder(root);
    cout<<endl;
    
    int x;
    cout<<"Give a value: ";
    cin>>x;

    if(searchBST(root,x)){
        cout<<"The value is Present!"<<endl;
    }
    else{
        cout<<"The value is not Present!"<<endl;
    }
}