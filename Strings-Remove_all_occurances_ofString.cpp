//Explanation of .find() and .erase() is in my DSA khata!!

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    string str; 
    cin>>str;
    int n=str.length();
    string part="abc";
    while(str.find(part)<str.length() && str.length()>0){
        str.erase(str.find(part),part.length());
    }
    cout<<str;
    return 0;
}
