//Real life implementation: Suppose I want to search a word in a dictionary. To search it I open a random page according to the first alphabet.
//Then I will search what comes after that alphabetically in an order in the dictionary and so on.This is where binary search is used.
//I can apply binary search only on sorted arrays (ascending/descending).


//If an array is sorted or a portion of it is sorted or half of its portion is sorted in ascending then half of it is in descending order Then 
//we should think of binary search instantly 

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
    sort(array.begin(),array.end());
    int target;
    cout<<"Enter a target value: ";
    cin>>target;
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(array[mid]<target){
            start=mid+1;
        }
        else if(array[mid]>target){
            end=mid-1;
        }
        else{
            cout<<"Index is: "<<mid;
            break;
        }
    }
    return 0;
}

// Suppose you have n elements.Each step, you divide by 2:

// Step	Size of remaining array
// 0	n
// 1	n/2
// 2	n/4
// 3	n/8
// 4	n/16
// ...	...
// k	1
// You keep dividing by 2 until 1 element remains.

//That’s why binary search  TC is O(log₂(n)).

// Suppose n = 16.
// Then:
// Step	Remaining array size
// 0	16
// 1	8
// 2	4
// 3	2
// 4	1
// After 1st step: 16 → 8
// After 2nd step: 8 → 4
// After 3rd step: 4 → 2
// After 4th step: 2 → 1
// Total steps = 4.

// And indeed It matches the mathematical formula=(log₂(n)).