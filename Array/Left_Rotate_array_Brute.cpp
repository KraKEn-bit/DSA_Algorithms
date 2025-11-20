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

    vector<int>temp(k);

    int n=arr.size();
    for(int i=0;i<k;i++){
        temp[i]=arr[i];    
    }

    //Shifting the elements of the array to the left 
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }

    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-n+k];
    }

    for(int e:arr){
        cout<<e<<" ";
    }
}