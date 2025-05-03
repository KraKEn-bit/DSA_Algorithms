//Explanation in my DSA Khata!!

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int isvalid(int freq1[],int freq2[]){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string part;
    cout<<"Enter a substring that is to be found: ";
    cin>>part;
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    int length_part=part.length();
    int freq_part[26]={0};
    for(int i=0;i<length_part;i++){
        freq_part[part[i]-'a']++;
    }

    int window_size=part.length();
    int length_str=str.length();
    for(int i=0;i<length_str;i++){
        int freq_str[26]={0};
        int window_indx=0,index=i;
        while(window_indx<window_size && index<length_str){
            freq_str[str[index]-'a']++;
            window_indx++;
            index++;
        }
        if(isvalid(freq_str,freq_part)){
            cout<<"True";
            return 0;
        }
    }
    cout<<"False";
    return 0;
}