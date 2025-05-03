#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    char strr[]="Rafsan kabir";
    //This will print The characters until there is a null terminator
    for(int i=0;strr[i]!='\0';i++){
        cout<<strr[i];  
    }
    cout<<endl;
    //But as it is a lengthy process we can use "cin.getline(str,strlength,delimiter)"
    //What is delimiter? ans: It is just an input; upto this character or input the printing will happen and rest after that won't be printed
    char str[100];
    cout<<"Enter a string by characters: ";
    cin.getline(str, 100, 'y');
    cout<<str<<endl; //Input: Islamic University of Technology Output:Islamic Universit

    char STR[101];
    cout<<"Enter a string: ";
    cin>>STR;
    cout<<STR;//Input: Rafsan Kabir Output: Rafsan

    //That's why we use 'string' variable!
    string name;
    cin>>name;
    cout<<"Your name is: "<<name;
    //This way also prints one word if there's multiple ones.So we also use 'getline' here.

    string word;
    cin.ignore();//If I didn't give this. But there's a small issue here: getline(cin, word); runs immediately after cin >> 
    //name;, and cin >> leaves a newline character (\n) in the buffer. So getline() may read that newline as an empty line unless you flush it.
    getline(cin, word);
    cout<<word;//If input: Rafsan Kabir Output: Rafsan Kabir
    return 0;
}