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

    int len = arr.size();
    int profit,maxProfit=INT_MIN;

    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(arr[i]>arr[j]){
                profit=0;
            }
            else{
            profit = arr[j]-arr[i];
            }
            maxProfit = max(maxProfit,profit);
        }
    }
    cout<<maxProfit;
}