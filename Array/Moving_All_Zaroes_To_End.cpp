#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>

using namespace std;

int main(){
    int numb;
    vector<int>arr;
    while(true){
        cin>>numb;
        if(numb==-1){
            break;
        }
        else{
            arr.push_back(numb);
        }
    }

    int n=arr.size();

    vector<int>zeros;
    vector<int>non_zeros;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeros.push_back(arr[i]);
        }
        else{
            non_zeros.push_back(arr[i]);
        }
    }
    non_zeros.insert(non_zeros.end(),zeros.begin(),zeros.end());

    for(int c:non_zeros){
        cout<<c<<" ";
    }
}