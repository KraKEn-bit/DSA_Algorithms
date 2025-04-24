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

//short cut for << and >>: 
//answer for << (left shift) = a*pow(2,b)
//answer for >> (Right shift) = a/pow(2,b)

//For right shift except the last one all of them goes right and the first one goes at last if we count from left