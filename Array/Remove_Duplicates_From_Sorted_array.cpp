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

    int len = array.size();
    int already_found=0;

    vector<int>result;
    for(int i=0;i<len;i++){
        if(result.empty() || result.back() != array[i]){
            result.push_back(array[i]);
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}