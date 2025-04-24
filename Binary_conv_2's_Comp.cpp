#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

//In Signed binary:-
// MSB = 0 → Positive
// MSB = 1 → Negative

int main(){
    string str;
    cout<<"Enter a number: ";
    cin>>str;
    int res,bin_numb,dec_numb;
    if(str[0]=='0'){
        cout<<"The number is positive!"<<endl;
        return 0;
    }
    else if(str[0]=='1'){
        cout<<"The number is negative!"<<endl;
        string copy=str;
        int len=str.length();
        for(int i=0;i<len;i++){
            if(copy[i]=='1'){
                copy[i]='0';
            }
            else if(copy[i]=='0'){
                copy[i]='1';
            }
            else{
                cout<<"It is an invalid binary"<<endl;
                return 0;
            }
        }
        int carry=1;
        for(int i=len-1;i>=0;i--){
            if(copy[i]=='0'){
                copy[i]='1';
                carry=0;
                break;
            }
            else if(copy[i]=='1'){
                copy[i]='0';
            }
        }
        dec_numb=stoi(copy,nullptr,2);
        dec_numb=-dec_numb+1;
        bin_numb=stoi(copy,nullptr,10);
    }
    cout<<"2's Compliment is: "<<endl;
    cout<<"binary form: "<<bin_numb<<endl;
    cout<<"decimal form: "<<dec_numb;
}