
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    int n=str.length();
        //Another way to reverse a string if not using library functions.
    // int i=0,j=n-1;
    // while(i<=j){
    //     swap(str[i],str[j]);
    //     i++;
    //     j--;
    // }
    reverse(str.begin(),str.end());
    string answer="";//So that each reversed words in perfect order gets printed by adding.
    for(int i=0;i<n;i++){
        string individual_word="";
    while(str[i] != ' ' && i < n){
        individual_word+=str[i];
        i++;
    }
    //After this we get like for example: Input: Rafsan Kabir. We get = 1st word= ribaK , 2nd word= nasfaR 
    reverse(individual_word.begin(),individual_word.end());
    //Then reverse each of them like Now we get: 1st word now Kabir and 2nd word now Rafsan
    if(individual_word.length()>0){
        answer+=" "+individual_word;//Then Add those reversed individual words to answer for priting.
    }
}
cout<<answer.substr(1);//This is to remove the 1st space. Because we initialized answer with "" it is for the space between 2 words but we don't want 
//this at 1st.
}