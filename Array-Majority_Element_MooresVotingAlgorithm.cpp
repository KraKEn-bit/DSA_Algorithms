#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int freq=0,ans=0;
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=array[i];
        }
        if(ans==array[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    cout<<"Majority element is: "<<ans;
    return 0;
}

//Example:
// You're in a room with people supporting different candidates. Every time you see a person supporting someone different from your current favorite, 
// you cancel them out — one supporter from each side walks out.The person with the most support will remain by the end.


// If an element appears more than half the time, then:
// 1.The count of that element is greater than the sum of all other elements combined.
// 2.So, any "cancellation" you do between the majority and minority elements will still leave the majority element standing.