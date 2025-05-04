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
    if(n1>n2){
    while(n2!=0){
        int rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    cout<<"GCD is: "<<n1;
}
if(n2>n1){
    while(n1!=0){
        int rem=n2%n1;
        n2=n1;
        n1=rem;
    }
    cout<<"GCD is: "<<n2;
}
//LCM is =(n1*n1)/GCD
}