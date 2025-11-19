#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>

using namespace std;

int main(){
    int max_element=INT_MIN;
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
    int len =array.size();
    for(int i=0;i<len;i++){
        if(array[i]>max_element){
            max_element=array[i];
        }
    }

    int sec_max_ele = INT_MIN;
    for(int i=0;i<len;i++){
        if(array[i]>sec_max_ele && array[i]<max_element){
            sec_max_ele=array[i];
        }
    }

    cout<<sec_max_ele;
}