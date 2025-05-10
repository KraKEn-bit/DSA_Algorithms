#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>
#include<unordered_set>

using namespace std;

int main(){
    int row,column;
    cout<<"Enter row: ";
    cin>>row;
    cout<<"Enter column: ";
    cin>>column;
    int a,b;
   vector<vector<int>>matrix(row,vector<int>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>matrix[i][j];
        }
    }
    unordered_set<int>set_value;
    int expected_sum=0,actual_sum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            actual_sum+=matrix[i][j];
            int value=matrix[i][j];
            if(set_value.find(value)!=set_value.end()){
                a=value;
            }
            set_value.insert(value);
        }
    }
    int total_elements = row * column;
    expected_sum = (total_elements * (total_elements + 1)) / 2;
    cout << "Missing number is: " << expected_sum +a-actual_sum;
    return 0;
}