#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

void digitsCount(int numb){
    int digits=0,count=0;
    cout<<"Digits of the number is: "<<endl;
    while(numb!=0){
        digits=numb%10;
        cout<<digits<<endl;
        count++;
        numb=numb/10;
    }
    cout<<"Count of the digits of the number is: "<<count<<endl;
}
bool isArmstrong(int number){
    int copyNumber=number;
    
    //Why took a copy? Ans: Because If I din't take a copy. After the while loop number=0;Then the sumofCubes will be compared with 0 not the original 
    //number. That's why i took a copy for the operation and for comparing the operated value I compare with the original number without changin 
    //anything of its digits.!!

    int sumofCubes=0,digits=0;
    while(copyNumber!=0){
        digits=copyNumber%10;
        sumofCubes+=(digits*digits*digits);
        copyNumber=copyNumber/10;
    }
    return sumofCubes==number;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    digitsCount(n);
    if(isArmstrong(n)){
        cout<<"The number is an Armstrong number!";
    }
    else{
        cout<<"Not an Armstrong number!";
    }
    return 0;
}