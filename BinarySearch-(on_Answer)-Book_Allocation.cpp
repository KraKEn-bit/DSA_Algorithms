//Problem Statement:
// You are given:
// n books (each with a certain number of pages).
// k students.

// Objective: Allocate the books to k students such that:
// Each student gets at least one book.
// Each book is assigned to exactly one student.
// The allocation is contiguous.
// The maximum number of pages assigned to a student is as small as possible.

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int isvalid(int arr[],int n,int k,int maxAllowedPage){
// This function checks whether it's possible to allocate books to k students such that no student gets more than maxAllowedPage pages.
// Logic:
// Start with the first student.
// Add books until the total exceeds maxAllowedPage(each mid from the binary search).
// If it exceeds, assign the current book to a new student and repeat.
// If the number of students used exceeds k, return false.
// Else, return true.

// Key Conditions:
// If a book has more pages than maxAllowedPage, return false immediately.
// Try to minimize the maximum number of pages while keeping allocations contiguous.
    int student=1,pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxAllowedPage){
            return false;
        }
        if(pages+arr[i]<=maxAllowedPage){
            pages+=arr[i];
        }
        else{
            student++;
            pages=arr[i];
        }
    }
    if(student>k){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    //Here I check from each each mid from the binary search that if it is valid or not. How to see? Ans: Suppose from BS I find mid=5. Now from
    //assigning the pages into 2 students we see one of them has max pages and thus we compare the mid with those max pages if mid<max-Right BS else Left BS
    //Then I store the mid value in an answer variable which got calculated from the isvalid() function and print it.
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int k;
    cout<<"Enter number of students: ";
    cin>>k;
    int ans=-1,res=0;
    if(k>n){
        //Checking the edge case which is If k>n suppose 4 books there but students are 5 in numbers. Then one of them won't have any books which is
        //not mentioned. I have to give everyone at least one book.
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++){
        res+=array[i];
    }
    int start=0,end=res;
    //why end=res and start=0? Ans: At initial stage students have no books and in best case scenario one of the students has the highest pages.

    //What If I Searched Array Indices Instead? Ans:If you binary searched over array indices (0 to n-1) instead of the total page range,
    // you’d be searching the wrong space.The problem is not about finding a specific book index,
    //but about finding a feasible value of maximum pages per student
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isvalid(&array[0], n, k, mid)){
            end=mid-1;
            ans=mid;
            //It means if a value is valid Try to find the smallest valid value possible
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans;
    return 0;
}

//Contiguous order means:refers to elements being stored next to each other in memory — without any gaps.You can store multiple element in the same index.
// Elements are stored in contiguous memory locations.
//Contiguous memory allocation: Memory is allocated in a single continuous block.