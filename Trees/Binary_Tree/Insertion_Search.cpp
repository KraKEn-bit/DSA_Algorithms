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

static int indx = -1;
Node* buildTree(vector<int>arr){
    indx++;
    Node* root = new Node(arr[indx]);

    if(arr[indx]==-1){
        return NULL;
    }

    root->left = buildTree(arr);
    root->right = buildTree(arr); 
    return root;
}

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else if(val > root->data){
        root->right = insert(root->right,val);
    }
    else{
        return root;
    }
}

bool searchBST(Node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (root->data == val) {
        return true;
    }
    else if (val < root->data) {
        return searchBST(root->left, val);
    }
    else {
        return searchBST(root->right, val);
    }
}

int main(){
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->data<<endl;


    cout<<"The value is at postion: "<<searchBST(root,20)<<endl;
}