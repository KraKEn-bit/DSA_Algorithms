#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>

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
    vector<int>arr2;
    int numb2;
    while(true){
        cin>>numb2;
        if(numb2==-1){
            break;
        }
        else{
            arr2.push_back(numb2);
        }
    }

    arr.insert(arr.end(),arr2.begin(),arr2.end());
    sort(arr.begin(),arr.end());

    int j=0;
    int n=arr.size();

    for(int i=1;i<n;i++){
        if(arr[i]!=arr[j]){
            j++;      
            arr[j]=arr[i];
        }
    }
    for(int i=0;i<=j;i++){
        cout<<arr[i]<<" ";
    }
}