#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
   int n;
    cout<<"Enter the number of characters: ";
    cin>>n;
vector<char> array(100);
for(int i=0;i<n;i++){
    cin>>array[i];
}
char ch;
int index=0;
for(int i=0;i<n;i++){
    ch=array[i];
    int count=0;
    //This while loop keeps checking until there's a different element.
    while(ch==array[i] && i<n){
        count++;
        i++;
    }
    //For a single character:
    if(count==1){
        array[index]=ch;
        index++;
    }
    else{
        array[index]=ch;
        index++;
        string str =to_string(count);
        //"to_string" is used to convert integer to a string
        for(int j=0;j<str.length();j++){
            array[index]=str[j];
            //so we are overwriting the rest occurances of a character with its counts except the 1st one.
            index++;
        }
    }
    i--;//so that it gets restarted to the last element of the same occurance.like 'aaabb' (meaning: upto 3rd 'a') 
    //and then for another character it restarts like after 'a' there's 'b'.
    
}
for(int i=0;i<index;i++){
    cout<<array[i];
}
cout<<endl;
cout<<"Length of the resized array is: ";
array.resize(index); //Why resize? Ans: Because until now the answer is a3b2c2c Here an extra c comes but We want only the resized
//So as we initialized index=0 and by each operation it gets added index=0,1,2,3,4,5,6 so resize will count that in 1,2,3,4,5,6

//To use ".resize()" We must use the array as a 'vector<char>' .!!
cout<<index<<endl;
}