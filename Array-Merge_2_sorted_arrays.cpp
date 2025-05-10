//It doesn't use merge sort algorithm!!!

//Merging 2 sorted arrays into an empty array.Those 2 arrays should be sorted. Now I will check each elements of array2 with array1. 
//If the elements of array1<array2 then it will move to the empty array else it will also move to the empty array but after the elements that are
//assigned already..in backwards. I have to check elements in backwards. After the operations if any elements are left push them directly to the rest of the
//place of the empty array.


//Now The sizes: i=n-1 (This is for the array1's size which I am iterating backwards for comparison)
//j=m-1 (This is for the array2's size which I am iterating backwards for comparison)                   [[as arrays start from o to (n-1)/(m-1)/(m+n-1)]]
//index=m+n-1 (This is for the empty array's size which I am iterating/pushing the elements in backwards)

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements for array1: ";
    cin>>n;
    vector<int>array1(n);
    for(int i=0;i<n;i++){
        cin>>array1[i];
    }
    int m;
    cout<<"Enter the number of elements for array2: ";
    cin>>m;
    vector<int>array2(m);
    for(int i=0;i<m;i++){
        cin>>array2[i];
    }
    vector<int>arr(m+n);
    int index=m+n-1;
    int i=n-1,j=m-1;
    while(i>=0 && j>=0){
       if(array1[i]<array2[j]){
            arr[index]=array2[j];
            index--;
            j--;
        }
        else{
            arr[index]=array1[i];
            index--;
            i--;
        }
    }
    //If any elements are left after the above operations. Then auto fillup the arr[index] with that left array2[j] if the element is in array2;
    while(j>=0){
        arr[index]=array2[j];
        index--;
        j--;
    }
       //If any elements are left after the above operations. Then auto fillup the arr[index] with that left array1[i] if the element is in array1;
    while(i>=0){
        arr[index]=array1[i];
        index--;
        i--;
    }

    for(int i=0;i<(m+n);i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}