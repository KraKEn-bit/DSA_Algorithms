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

    int n=arr.size();
    int pivot = -1;

    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            pivot=i;
            break;
        }
        if(pivot=-1){
            sort(arr.rbegin(),arr.rend());
        }
    }

    for(int i=n-1;i>pivot;i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[pivot]);
            break;
        }
        //break;
    }

    int start = pivot+1 , end=n-1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}