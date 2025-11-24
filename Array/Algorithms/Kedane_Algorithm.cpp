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
    
    while (true) {
        if (cin.peek() == '\n') {
            cin.ignore(); 
            break;
        }
        cin >> numb;
        arr.push_back(numb);
    }

    int len=arr.size();
    int res,count,maxres=INT_MIN,currRes;
    for(int i=0;i<len;i++){
        res=0;
        for(int j=i;j<len;j++){
            res+=arr[j];
            maxres = max(maxres,res);
        }
    }
    cout<<maxres;
}