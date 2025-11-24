// Stock_Buy_Sell

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
    int profit,minPrice=INT_MAX;
    int maxProfit = 0;
    for(int i=0;i<len;i++){
        minPrice = min(minPrice,arr[i]);
        maxProfit = max(maxProfit,arr[i]-minPrice);
    }
    cout<<maxProfit;
}