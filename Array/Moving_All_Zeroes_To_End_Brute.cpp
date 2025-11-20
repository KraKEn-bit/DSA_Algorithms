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

    int n1=arr.size();

    vector<int>temp;
    for(int i=0;i<n1;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<n1;i++){
        arr[i]=temp[i];
    }
    int n2 = temp.size();

    for(int i=n2;i<n1;i++){
        arr[i]=0;
    }

    for(int c:arr){
        cout<<c<<" ";
    }
}