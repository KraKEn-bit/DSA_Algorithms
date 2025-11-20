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
    set<int>arr;
    while(true){
        cin>>numb;
        if(numb==-1){
            break;
        }
        else{
            arr.insert(numb);
        }
    }
    set<int>arr2;
    int numb2;
    while(true){
        cin>>numb2;
        if(numb2==-1){
            break;
        }
        else{
            arr2.insert(numb2);
        }
    }
    
    arr.insert(arr2.begin(),arr2.end());
    
    for(int c:arr){
        cout<<c<<" ";
    }

}