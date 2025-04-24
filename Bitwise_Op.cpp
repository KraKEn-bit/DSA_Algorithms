#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int operation;
    int a,b;
    cin>>a>>b;
    //operation=a&b; result=2 (if a=6 and b=10)
    //operation=a|b; result=14 
    //operation=a^b; result=12 
    //operation=b<<2; result=40
    operation=b>>1;
    cout<<operation;
}