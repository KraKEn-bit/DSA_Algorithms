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
    vector<vector<int>>matrix(row,vector<int>(column));
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>matrix[i][j];
        }
    }
    vector<int>answer;
    int start_row=0,end_row=row-1;
    int start_column=0,end_column=column-1;
    while(start_row<=end_row && start_column<=end_column){
        //Top Boundary
        for(int i=start_column;i<=end_column;i++){
            answer.push_back(matrix[start_row][i]);
        }
        //Right boundary
        for(int i=start_row+1;i<=end_row;i++){
            answer.push_back(matrix[i][end_row]);
        }
        //Bottom Boundary
        for(int i=end_column-1;i>=start_column;i--){
            if(start_row==end_row){
                break;
            }
            answer.push_back(matrix[end_row][i]);
        }
        //Left Boundary
        for(int i=end_row-1;i>=start_row+1;i--){
            if(start_column==end_column){
                break;
            }
            answer.push_back(matrix[i][start_column]);
        }
        start_row++;
        start_column++;
        end_row--;
        end_column--;
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
 
//Here Why "while(start_row<=end_row && start_column<=end_column)"?
//Ans: It's because after "start_row++;start_column++;end_row--;end_column--;" Every row and columns will shift towards each other and there will be
//a time when the top and bottom rows, top and bottom columns will cross or come together at that moment the loop will brea;


//Why the if conditions?
//Ans: Because for example: The row and column number all together means an even matrix. It will print upto the mid row and column and it will work fine
//for the task even if we didn't insert the conditions. 
//But for odd matrixes where and row and column number are odd. In that case when the rows and columns keep shifting towards the mid. At one time the rows
//and columns will come together and upto that part rest of the numbers will be printed except the mid row's or column's elements.That's why the 
//conditions are needed.!!