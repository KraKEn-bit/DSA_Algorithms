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
Node * buildTree(vector<int>arr){
    indx++;
    if(arr[indx]==-1){
        return NULL;
    }

    Node* root = new Node(arr[indx]);

    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root;
}


int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(leftheight,rightheight)+1;
}

int diameteroftree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftiter = diameteroftree(root->left);
    int rightiter = diameteroftree(root->right);

    int curr = height(root->left) + height(root->right);

    return max(max(leftiter,rightiter),curr);
}


int main(){
    vector<int>array = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(array);

    cout<<"Diameter of the Tree is: "<<diameteroftree(root);
}