#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i=1;i<n;i++){
        //Why i=1? Because we aready assumed that the previous elements are sorted. We compare the unsorted ones whith them.
        int current=array[i];
        int prevIndex=i-1;
        while(prevIndex>=0 && array[prevIndex]>current){
            array[prevIndex+1]=array[prevIndex];
            prevIndex--;
    //why previndex--? Because if we swap the prev+1 and prev then that space becomes empty to remove that empty space we are reducing the space.
        }
        array[prevIndex+1]=current;
        //why this instead of array[previndex]=current?
        //You're shifting all elements greater than current one position to the right.
        // prevIndex + 1 is the correct place to insert current after all the bigger elements have been moved.
        // If you wrote array[prevIndex] = current;, you'd overwrite a value that hasn't been shifted yet — breaking the algorithm.
    }
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}