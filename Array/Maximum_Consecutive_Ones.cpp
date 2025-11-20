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

    int n=arr.size();

    int count;
    int maxCount = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
        count=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]==1){
                count++;
            }
            else{
                break;
            }
        }
        maxCount = max(maxCount, count);
    }
}
    cout<<maxCount;
}