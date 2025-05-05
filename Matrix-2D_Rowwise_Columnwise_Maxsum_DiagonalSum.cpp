#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

void Diagonal_Sum(vector<vector<int>>&mat,int row,int col){
    int diagonalsum=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(j==i){
                diagonalsum+=mat[i][j];
            }
            else if(j==row-i-1){
                diagonalsum+=mat[i][j];
            }
        }
    }
    
    //Here the conditions are ignoring the double counted values for odd dimensioned matrix of rows and columns. suppose: 1 2 3 4 5 6 7 8 9 Here 5 
    //comes 2 times when counting. So that 5 is counted 1 times. If I wanted two times: Condition: if(j==i || j=(row or col)-i-1) as row==col

    cout<<"Diagonal sum of the matrix is: "<<diagonalsum<<endl;
}
void rowwise_MaxSum(vector<vector<int>>&mat,int row,int col){
    int maxrowsum=INT_MIN;
    for(int i=0;i<row;i++){
        int rowsum=0;
        for(int j=0;j<col;j++){
            rowsum+=mat[i][j];
        }
        maxrowsum=max(maxrowsum,rowsum);
    }
    cout<<"Row_Wise Max Sum is: "<<maxrowsum<<endl;
}
void columnwise_MaxSum(vector<vector<int>>&mat,int row,int col){
    int maxcolsum=INT_MIN;
    for(int j=0;j<col;j++){
        int colsum=0;
        for(int i=0;i<row;i++){
            colsum+=mat[i][j];
        }
        maxcolsum=max(maxcolsum,colsum);
    }
    cout<<"Column wise Max Sum: "<<maxcolsum<<endl;
}
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
    Diagonal_Sum(matrix,row,column);
    rowwise_MaxSum(matrix,row,column);
    columnwise_MaxSum(matrix,row,column);
    return 0;
}