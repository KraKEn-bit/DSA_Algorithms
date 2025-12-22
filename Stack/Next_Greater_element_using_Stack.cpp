#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> array(n);  
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    vector<int> next_greater_el(n, -1);  
    stack<int> st; 

    for(int i = 0; i < n; i++){
        while(!st.empty() && array[i] > array[st.top()]){
            next_greater_el[st.top()] = array[i];  
            st.pop();
        }
        st.push(i);
    }

    for(int x : next_greater_el){
        cout << x << " ";
    }
    cout << endl;
}