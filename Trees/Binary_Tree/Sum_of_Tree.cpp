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

int sumTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int lefttree = sumTree(root->left);
    int righttree = sumTree(root->right);

    return lefttree + righttree + root->data;
}

int main(){
    vector<int>arr = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(arr);

    cout<<"The Sum of the Tree Nodes is: "<<sumTree(root);
}