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

    int k;
    cin>>k;

    int n=arr.size();

    int maxCount=0,count;
    int res;
    for(int i=0;i<n;i++){
        count=0,res=0;
        for(int j=i;j<n;j++){
            res+=arr[j];
            if(res==k){
                break;
            }
            count++;
        }
        maxCount=max(maxCount,count);
    }
    cout<<maxCount;
}