#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    stack<int> st1, st2;
    vector<int> array;

    int numb;
    while(true){
        cin >> numb;
        if(numb == -1){
            break;
        }
        array.push_back(numb);
        st1.push(numb);
    }

    int n = array.size();

    for(int i = 0; i < n; i++){
        int current = array[i];
        int nge = -1; 

        for(int j = 1; j < n; j++){
            int idx = (i + j) % n;
            if(array[idx] > current){
                nge = array[idx];
                break;
            }
        }

        st2.push(nge);
    }

    vector<int> result;
    while(!st2.empty()){
        result.push_back(st2.top());
        st2.pop();
    }

    for(int i = result.size()-1; i >=0; i--){
        cout << result[i] << " ";
    }
}
