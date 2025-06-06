#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>
#include<unordered_set>
//Why unordered_Set used?
//In C++, an unordered_set is a container from the Standard Template Library (STL) that stores unique elements in no particular order.
//It is implemented using a hash table, which allows for average constant time (O(1)) complexity for insertion, deletion, and lookup operations.

using namespace std;

int main(){
    int row,column;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter column: ";
    cin>>column;
   vector<vector<int>>matrix(row,vector<int>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>matrix[i][j];
        }
    }
    unordered_set<int>set_value;
    cout<<"Repeated value is: ";
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            int value=matrix[i][j];
            if(set_value.find(value)!=set_value.end()){
                cout<<value;
            }
            set_value.insert(value);
        }
    }
    return -1;
}