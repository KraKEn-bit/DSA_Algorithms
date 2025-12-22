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

vector<int> next_smaller_element(vector<int>& arr, int n) {
    vector<int> next_small_ele(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            next_small_ele[i] = n;
        } 
        else {
            next_small_ele[i] = st.top();
        }
        st.push(i);
    }
    return next_small_ele;
}

vector<int> prev_smaller_element(vector<int>& arr, int n) {
    vector<int> prev_small_ele(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            prev_small_ele[i] = -1;
        } 
        else {
            prev_small_ele[i] = st.top();
        }
        st.push(i);
    }
    return prev_small_ele;
}

int main() {
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int mod = (int)(1e9 + 7);

    vector<int> prev_small_ele = prev_smaller_element(array, n);
    vector<int> next_small_ele = next_smaller_element(array, n);

    long long total = 0;

    for (int i = 0; i < n; i++) {
        int left = i - prev_small_ele[i];
        int right = next_small_ele[i] - i;
        total = (total + (long long)left * right * array[i])%mod;
    }

    cout << total;
}
