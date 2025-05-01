//Bubble Sort:Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, 
//compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.

//How it works:
// Start from the beginning of the array.
// Compare the first two elements.
// If the first is greater than the second, swap them.
// Move to the next pair and repeat.
// At the end of the first pass, the largest element is at the end.
// Repeat the process for the rest of the array (ignoring the sorted part at the end).



// After each full pass, the largest unsorted element bubbles up to its correct position at the end.
// So after i passes, the last i elements are already sorted, and we don't need to touch them again.
// That’s why the inner loop goes only till n - i - 1.

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
    int isswap;
    for(int i=0;i<n-1;i++){
        isswap=0;
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
            swap(array[j+1],array[j]);
            isswap=1;
            }
        }
    }
    if(!isswap){
        cout<<"Already sorted";
    }
    else{
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
    return 0;
}


// Suppose an arr = [5, 3, 8, 4, 2], n = 5

// i = 0 → j runs from 0 to 3 → compares 4 pairs
// i = 1 → j runs from 0 to 2 → compares 3 pairs
// i = 2 → j runs from 0 to 1 → compares 2 pairs
// i = 3 → j runs from 0 to 0 → compares 1 pair

//At this point the array is sorted