//Using Bitwise operators:(XOR)
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        res^=array[i];
    }
    cout<<"The single occurance number is: "<<res;
    return 0;
}  