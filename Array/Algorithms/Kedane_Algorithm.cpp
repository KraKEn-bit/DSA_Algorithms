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

    int currSum=0,maxSum = INT_MIN;

    for(int i=0;i<len;i++){
        currSum+=arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    }
    cout<<maxSum;
}