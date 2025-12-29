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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL){
        return NULL;
    }

    if(root == p || root == q){
        return root;
    }

    Node* leftLCA = lowestCommonAncestor(root->left, p, q);
    Node* rightLCA = lowestCommonAncestor(root->right, p, q);

    if(leftLCA && rightLCA){
        return root;
    }
    else if(leftLCA != NULL){
        return leftLCA;
    }
    else{
        return rightLCA;
    }
}

Node* findNode(Node* root, int val){
    if(root == NULL) return NULL;

    if(root->data == val){
        return root;
    }

    Node* left = findNode(root->left, val);
    if(left != NULL) return left;

    return findNode(root->right, val);
}

int main(){
    vector<int> array = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};

    Node* root = buildTree(array);

    int pv, qv;
    cout<<"Give value for p: ";
    cin>>pv;

    cout<<"Give value for q: ";
    cin>>qv;

    Node* p = findNode(root, pv);
    Node* q = findNode(root, qv);

    Node* ans = lowestCommonAncestor(root, p, q);

    if(ans != NULL){
        cout<<"Lowest Common Ancestor : "<<ans->data;
    }
    else{
        cout<<"LCA not found";
    }
}
