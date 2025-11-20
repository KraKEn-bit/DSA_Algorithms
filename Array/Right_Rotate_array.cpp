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
    for(int i=k+1;i<n;i++){
        temp.push_back(arr[i]);
    }
    arr.erase(arr.begin()+k+1,arr.end());

    arr.insert(arr.begin(),temp.begin(),temp.end());

    for(int c:arr){
        cout<<c<<" ";
    }
}