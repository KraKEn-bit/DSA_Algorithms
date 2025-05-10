//Using Hash Map:

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>
#include<unordered_map>

//Why unordered_map is used:
//unordered_map allows constant time (O(1)) 
//average-case lookups for checking whether a number exists — much faster than using a loop to search linearly (which would take O(n)).

// 1)It stores each number as a key.
// 2)The value is the index where the number appeared.

using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int>array(n);
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int target;
    cout<<"Enter a target: ";
    cin>>target;
    unordered_map<int, int> map_name;
    for(int i=0;i<n;i++){
        int first=array[i];
        int second=target-first;
        if(map_name.find(second)!=map_name.end()){
            //If it is "==" Then not found else it is found
            cout<<map_name[second]<<" "<<i;
        }
        // This checks whether the number second = target - array[i] has already been seen earlier in the array 
        // (i.e., already inserted into the unordered_map). 
        // If it has, then it prints the index of that earlier number and the current index i.
        map_name[first]=i;
        //Update the array element if not found.
    }
    return -1;
}



//For example: Array-5 2 11 7 15 and target=9
// i = 0:
// array[0] = 5
// second = target - array[0] = 9 - 5 = 4
// map_name.find(4) == map_name.end() → false (4 is not in the map)
// → Add 5 to map: map_name[5] = 0

// i = 1:
// array[1] = 2
// second = 9 - 2 = 7
// map_name.find(7) → not found
// → Add 2 to map: map_name[2] = 1

// i = 2:
// array[2] = 11
// second = 9 - 11 = -2
// map_name.find(-2) → not found
// → Add 11 to map: map_name[11] = 2

// i = 3:
// array[3] = 7
// second = 9 - 7 = 2
// map_name.find(2) → found at index 1
// ✅ So it prints: 1 3 (because array[1] + array[3] = 2 + 7 = 9)