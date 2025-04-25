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
    int freq=0,ans=0;
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=array[i];
        }
        if(ans==array[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    cout<<"Majority element is: "<<ans;
    return 0;
}