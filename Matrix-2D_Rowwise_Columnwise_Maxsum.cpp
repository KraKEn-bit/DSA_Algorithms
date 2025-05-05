#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

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
    rowwise_MaxSum(matrix,row,column);
    columnwise_MaxSum(matrix,row,column);
    return 0;
}