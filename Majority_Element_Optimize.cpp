#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    sort(array.begin(),array.end());
    int freq=1,answer=array[0];
    for(int i=0;i<n;i++){
        if(array[i]==array[i-1]){
            freq++;
        }
        else{
            freq=1;
            answer=array[i];
        }
        if(freq>n/2){
            cout<<"Majority element is: "<<answer;
            break;
        }
    }
    return 0;
}