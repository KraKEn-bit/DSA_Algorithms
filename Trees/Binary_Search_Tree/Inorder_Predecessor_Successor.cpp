#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

// 🔹 forward declaration (REQUIRED)
Node* insert(Node* root, int val);

Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int x : arr){
        root = insert(root, x);
    }
    return root;
}

Node* insert(Node* root, int val){
    Node* newNode = new Node(val);

    if(root == NULL){
        root = newNode;
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    else{
        return root;
    }

    return root;
}

Node* rightMostinLeftsubTree(Node* root){
    Node* ans = NULL;

    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}

Node* leftMostinRightsubTree(Node* root){
    Node* ans = NULL;

    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}

vector<int> getPredSucc(Node* root, int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        }
        else if(key > curr->data){
            pred = curr;
            curr = curr->right;
        }
        else{
            if(curr->left != NULL){
                pred = rightMostinLeftsubTree(curr->left);
            }
            if(curr->right != NULL){
                succ = leftMostinRightsubTree(curr->right);
            }
            break;
        }
    }

    vector<int> ans;

    if(pred != NULL){
        ans.push_back(pred->data);
    }
    else{
        ans.push_back(-1);
    }

    if(succ != NULL){
        ans.push_back(succ->data);
    }
    else{
        ans.push_back(-1);
    }

    return ans;
}

int main(){
    vector<int> arr = {10, 5, 15, 3, 7, 12, 18};

    Node* root = buildBST(arr);

    int key;
    cout << "Enter key: ";
    cin >> key;

    vector<int> result = getPredSucc(root, key);

    cout << "Predecessor: " << result[0] << endl;
    cout << "Successor: " << result[1] << endl;

    return 0;
}
