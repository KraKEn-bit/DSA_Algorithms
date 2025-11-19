// 2 Pointer Approach

#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>

using namespace std;

int main(){
    vector<int>arr;
    int numb;
    while(true){
        cin>>numb;
        if(numb==-1){
            break;
        }
        else{
            arr.push_back(numb);
        }
    }

    int j=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]!=arr[j]){
            j++;
            arr[j]=arr[i];
        }
    }
    for(int i=0;i<=j;i++){
        cout<<arr[i]<<" ";
    }
}