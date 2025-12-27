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
        left=right=NULL;
    }
};

static int indx=-1;

Node* buildTree(vector<int>array){
    indx++;
    Node* root = new Node(array[indx]);
    if(array[indx]==-1){
        return NULL;
    }
    root->left = buildTree(array);
    root->right = buildTree(array);
    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    queue<Node*>q;
    q.push(root);

    while(q.size()>0){
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}


int main(){
    vector<int>array = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(array);

    cout<<"Preorder sequence: "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Inorder sequence: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Postorder sequence: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"LevelOrder Sequence: "<<endl;
    levelOrder(root);
}