#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of containers: ";
    cin>>n;
    vector<int>container(n);
    for(int i=0;i<n;i++){
        cin>>container[i];
    }
    int start=0,end=n-1,area=0;
    while(start<end){
        int h=min(container[start],container[end]);
        int w=end-start;
        area=max(area,h*w);
        if(container[start]<container[end]){
         start++;
        }
        else{
         end--;
        }
     }
     cout<<"The maximum amount of water a container can store is: "<<area;
     return 0;
}