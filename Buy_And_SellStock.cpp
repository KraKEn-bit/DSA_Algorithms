#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of prices: ";
    cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    // int maxele=0,res;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(array[i]<array[j]){
    //             res=array[j]-array[i];
    //             maxele=max(res,maxele);
    //         }
    //     }
    // }
    int bestbuy=price[0],maxProfit=0;
    for(int i=1;i<n;i++){
        bestbuy=min(bestbuy,price[i]);
        if(price[i]>bestbuy){
            maxProfit=max(maxProfit,price[i]-bestbuy);
        }
    }
    cout<<"Maximum profit from the transaction is: "<<maxProfit;
}

//If I use 2 loops the way I did it will exceed the limit: 1 <= prices.length <= 105 
//Which will cause time limit exceed because of O(n^2)

//The above code not showing any TLE as it is O(n)