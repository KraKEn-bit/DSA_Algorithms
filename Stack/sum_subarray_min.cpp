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
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    stack<int>temp;

    int min_element;
    cout<<"Outputs: "<<endl;
    while(n--){
        for(int i=0;i<n+1;i++){
            min_element=INT_MAX;
            for(int j=i;j<n+1;j++){
                min_element = min(array[j],min_element); 
            }
            temp.push(min_element);
        }
    }
    int res = 0;
    while(!temp.empty()){
        res+=temp.top();
        temp.pop();
    }

    cout<<res;
}