#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>

using namespace std;

int main(){
    vector<int>array;
    int numb;
    
    while(true){
        cin>>numb;
        if(numb==-1){
            break;
        }
        else{
            array.push_back(numb);
        }
    }

    int max_numb = INT_MIN;
    for(int i=0;i<array.size();i++){
        if(array[i]>max_numb){
            max_numb=array[i];
        }
    }
    cout<<max_numb;

    //cout<<array.size();
}