#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    //To validate a prime number, Instead of going for every numbers and taking another loop to ensure if it's a prime number that will take like O(n^2) or 
    //more. The more efficient way to find prime number is: To find if N is divisible by any number from (2 to √n). 
    
    //How to find √n? Ans: i*i<=n
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            cout<<"It's not a prime number";
            return 0;
        }
    }
    cout<<"It's a prime number";
    return 0;
}