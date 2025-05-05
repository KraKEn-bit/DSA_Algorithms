#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int row,column;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter column: ";
    cin>>column;
    vector<vector<int>>matrix(row, vector<int>(column));
    //Why Write like this?
    //Ans:This line creates a 2D vector (matrix) with:
    // row number of rows, and each row is a vector<int> with column number of elements.
    //It means: "Create a vector of row vectors, where each vector has column integers initialized to 0."


    //If I didn't write this: This only creates the outer vector with row empty inner vectors (each inner vector has size 0), 
    //and you'd get an out-of-bounds error when trying to assign matrix[i][j]. For example: vector<vector<int>>matrix;

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>matrix[i][j];
        }
    }
    vector<pair<int,int>> pairs;
    int target;
    cout<<"Enter a target value: ";
    cin>>target;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(matrix[i][j]==target){
                pairs.emplace_back(i, j);
            }
        }
    }
    for(int i=0;i<pairs.size();i++){
        cout<<pairs[i].first<<" "<<pairs[i].second;
    }
    return 0;
}
