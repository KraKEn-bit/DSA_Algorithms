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

//An Armstrong number (also known as a narcissistic number, pluperfect number, or pluperfect digital invariant) 
//is a number that is equal to the sum of its digits each raised to the power of the number of digits.

bool isArmstrong(int number){
    int copyNumber=number;
    
    //Why took a copy? Ans: Because If I din't take a copy. After the while loop number=0;Then the sumofCubes will be compared with 0 not the original 
    //number. That's why i took a copy for the operation and for comparing the operated value I compare with the original number without changin 
    //anything of its digits.!!

    int count_digits=0;
    //counting digits:
    while (copyNumber != 0) {
        count_digits++;
        copyNumber /= 10;
    }

    copyNumber=number;
    double sum=0,digits=0;
    while(copyNumber!=0){
        digits=copyNumber%10;
        sum+=pow(digits,count_digits); 
        //This is counting double values that's why there's a rounding value problem If I gsve integer values in pow().
        copyNumber=copyNumber/10;
    }
    return sum==number;
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