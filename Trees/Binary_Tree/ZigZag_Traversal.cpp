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

static int indx = -1;
Node* buildTree(vector<int>arr){
    indx++;
    if(arr[indx]==-1){
        return NULL;
    }  

    Node* root = new Node(arr[indx]);

    root->left = buildTree(arr);
    root->right = buildTree(arr);
    return root;
}

vector<vector<int>> zigzagLevelOrder(Node* root){
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }

    queue<Node*> q;
    q.push(root);

    int level = 0;

    while(!q.empty()){
        int size = q.size();
        vector<int> levels;

        for(int i = 0; i < size; i++){
            Node* curr = q.front();
            q.pop();

            levels.push_back(curr->data);

            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }

        if(level % 2 == 1){
            reverse(levels.begin(), levels.end());
        }

        res.push_back(levels);
        level++;
    }
    return res;
}



int main(){
    vector<int> array = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(array);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    cout << "ZigZag Traversal Output: "<<endl;
    for(auto level : ans){
        for(int x : level){
            cout << x << " ";
        }
        cout << endl;
    }
}
