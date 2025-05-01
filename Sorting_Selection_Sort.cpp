//Selection Sort: It checks the minimum element of an unsorted part of an array then swap it to the lowest index possible.
//For every i's iteration I am assuming the ith index as the minimum and then compare it with its adjacent elements until the adjacent elements are
//small enough to be called the smallestindex then swaps ith element with the smallesindex's one.

#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }

    for (int i = 0; i < n; i++){
        int smallestIndex = i;
        for (int j = i + 1; j < n; j++){
            if (array[j] < array[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(array[i], array[smallestIndex]);
    }
        for (int i = 0; i < n; i++){
            cout<<array[i]<<" ";
        }
    return 0;
}