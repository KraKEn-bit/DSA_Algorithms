#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>

using namespace std;

int main(){
    set<int> arr;
    int numb;
    while(true){
        cin>>numb;
        if(numb==-1){
            break;
        }
        else{
            arr.insert(numb);
        }
    }
    for(int x : arr){
        cout<<x<<" ";
    }
}