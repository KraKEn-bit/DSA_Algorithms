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

    vector<int>temp(k);
    for(int i=n-k;i<n;i++){
        temp[i-(n-k)]=arr[i];
    }

    //Shifting elements to the right
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }

    for(int c:arr){
        cout<<c<<" ";
    }
}