#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    int numb;
    vector<int>arr;
    
    while (true) {
        if (cin.peek() == '\n') {
            cin.ignore(); 
            break;
        }
        cin >> numb;
        arr.push_back(numb);
    }

    int len=arr.size();
    int res,count,maxres=INT_MIN,currRes;
    int start,end;

    for(int i=0;i<len;i++){
        res=0;
        for(int j=i;j<len;j++){
            res+=arr[j];
            //maxres=max(maxres,res);
            if(res>maxres){
                maxres=res;
                start=i;
                end=j;
            }
        }
    }
    cout<<"Elements are: "<<endl;
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Max Sum: "<<maxres;
}