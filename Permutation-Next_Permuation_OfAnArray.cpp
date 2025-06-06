//Next Permutation:
//Given a sequence of numbers, the next permutation is the next lexicographically greater arrangement of those numbers. 
//If no such arrangement exists (i.e., the array is sorted in descending order), 
//the next permutation is the lowest possible order (i.e., sorted ascending).


//The concept:
// 1. Identify the "pivot":
// Traverse the array from right to left.
// Find the first pair where the left number is less than the number on its right.
// This position is called the pivot.
// Why? Because this is the point where a change can be made to make a "larger" permutation.

// 2. Find the smallest number greater than the pivot (to the right):
// From the right end, find the smallest number greater than the pivot value.
// Swap these two numbers.
// Why? This creates the smallest possible increase.
// 3. Reverse the part of the array after the pivot:
// After the pivot, the rest of the array is in decreasing order.
// Reverse it to get the smallest possible arrangement for that section.

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
    int pivot=-1;
    for(int i=n-2;i>=0;i--){//Here If I didn't give i=n-2 the array[i+1] will mean out of bound access that will indicate error.As I am comparing
        //with the next element.
        if(array[i]<array[i+1]){
            pivot=i;
            break;
        }
    }

    if(pivot==-1){//This is to be notified if there's no element that is greater than the after element like: 5 4 3 2 1 Then it only returns the reverse order
        sort(array.begin(),array.end());
        return 0;
    }

    for(int i=n-1;i>pivot;i--){
        if(array[i]>array[pivot]){
            swap(array[i],array[pivot]);
            break;
        }
    }
    int i=pivot+1;
    int j=n-1;
    while(i<=j){
        swap(array[i],array[j]);
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}