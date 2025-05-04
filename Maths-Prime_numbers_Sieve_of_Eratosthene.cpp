//Explanation in DSA khata!!

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
    vector<bool>isprime(n+1,true); //Initializing the vector array with 'true' upto (n+1) times!
    int count=0;
    for(int i=2;i<n;i++){
        if(isprime[i]){
            //Suppose i is at 2. Now it will assume this as prime and its multiples also prime.
            count++;
            for(int j=i*2;j<n;j=j+i){
            //as Multiples have been assumed as prime values. They are mentioned as false. and except them are counted
                isprime[j]=false;
            }
        }
    }
    cout<<"The count of prime Numbers Upto N is: "<<count;
    return 0;
}