#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

void reverseNumber(int numb){
    int rem,reverse=0;
    while(numb!=0){
        rem=numb%10;
        reverse=(reverse*10)+rem;//Reversing a number For example:
        //Input:7654 Now: 4*10+5=45,45*10+6=456,456*10+7=4567 Output:4567
        numb=numb/10;
    }
    cout<<"Reverse number is: "<<reverse<<endl;
}
void checkPalindrome(int number){
    int rem,reverse=0;
    int original=number,copyNumb=number;
    while(copyNumb!=0){
        rem=copyNumb%10;
        reverse=(reverse*10)+rem;
        copyNumb=copyNumb/10;
    }
    if(reverse==original){
        cout<<"It is a palindrome number!";
    }
    else{
        cout<<"Not a plindrome number!";
    }
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    reverseNumber(n);
    checkPalindrome(n);
    return 0;
}