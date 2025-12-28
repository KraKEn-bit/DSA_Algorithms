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

static int indx;

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


bool isidentical(Node* p,Node* q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }

    bool isleftsame = isidentical(p->left,q->left);
    bool isrightsame = isidentical(p->right,q->right);

    if((isleftsame && isrightsame) && (p->data == q->data)){
        return true;
    }
    else{
        return false;
    }
}

bool issubTree(Node* root,Node* subRoot){
    if(root==NULL){
        return false;
    }
    if(subRoot==NULL){
        return true;
    }

    if(isidentical(root,subRoot)){
        return true;
    }
    else if(issubTree(root->left,subRoot)){
        return true;
    }
    else if(issubTree(root->right,subRoot)){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    vector<int> arr1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> arr2 = {3,4,-1,-1,5,-1,-1};

    indx = -1;
    Node* root = buildTree(arr1);

    indx=-1;
    Node* subRoot = buildTree(arr2);

    if(issubTree(root,subRoot)){
        cout<<"Array2 is subtree of Array1"<<endl;
    }
    else{
        cout<<"Array2 is not subtree of Array1"<<endl;
    }
}