//2 Pointer approach to find if A string is palindrome

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

//Alphanumeric Values are values that are between a-z,A-Z,0-9

int main(){
    string str; 
    cin>>str;
    int n=str.length();
    int start=0,end=n-1;
    int not_found=0;
    while(start<end){
        if(!isalnum(str[start])){
            start++;
            continue;
        }
        if(!isalnum(str[end])){
            end--;
            continue;
        }
        if(tolower(str[start])==tolower(str[end])){
            start++;
            end--;
        }
        else{
            not_found = 1;
            break;
        }
    }
    if(not_found){
        cout << "Not a palindrome";
    }
    else{
        cout << "A palindrome!";
    }
    return 0;
}