//Dutch_National_Flag_Algorithm: Explanation is in my note khara!!!

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int mid=0,high=n-1,low=0;
    while(mid<=high){
        if(array[mid]==0){
            swap(array[low],array[mid]);
            low++;
            mid++;
        }
        else if(array[mid]==1){
            mid++;
        }
        else{
            swap(array[mid],array[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

//Here there is a Difference between If I used "if" statement instead of 'else if' and 'else'. Some testcases won't run for this.Why?
//Suppose array[mid] == 2. You swap it with array[high] and decrease high.
//But you do not increment mid, because you're supposed to recheck the new array[mid].
//However, if you use multiple if statements, the next if(array[mid] == 1) or if(array[mid] == 0) 
//may also get triggered in the same loop iteration, even though array[mid] has changed due to a swap.

//SO:
// if-else if-else: Ensures one action per mid position per iteration → correct.
// if-if-if: May perform multiple actions on the same mid index in one iteration → leads to bugs.