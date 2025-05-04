#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n1,n2;
    cout<<"Enter number1: ";
    cin>>n1;
    cout<<"Enter number2: ";
    cin>>n2;
    if(n1==0){
        cout<<"GCD is:: "<<n2 << endl;
    }
    else if(n2==0){
        cout<<"GCD is: "<< n1 << endl;
    }
    else {
        int gcd=1;
        for(int i=1;i<=min(n1,n2);i++){
            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
        }
        cout<<"GCD is: "<<gcd << endl;
    }
}