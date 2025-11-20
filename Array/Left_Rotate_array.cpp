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
    int k;
    cin>>k;

    int n=arr.size();
    k=k%n;
    
    vector<int>temp;
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    arr.erase(arr.begin(), arr.begin() + k);

    arr.insert(arr.end(),temp.begin(),temp.end());
    
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}