//This problem is for "If first integer of each row is greater than the last integer of the previous row!!"

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

bool searchRow(vector<vector<int>>& mat, int target, int mid_row) {
    int start = 0, end = mat[mid_row].size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (target == mat[mid_row][mid]) {
            return true;
        } else if (target > mat[mid_row][mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    int row, column;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> column;
    vector<vector<int>> matrix(row, vector<int>(column));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter a target: ";
    cin >> target;
    //Here I am finding the unique row's first and second element and searching if the target is in between. If in between then search if in the matrix
    //int that row between first and second the target exist. If exists-True else False
    int start_row = 0, end_row = row - 1;
    while (start_row <= end_row) {
        int mid_row = start_row + (end_row - start_row) / 2;
        if (target >= matrix[mid_row][0] && target <= matrix[mid_row][column - 1]) {
            //Until Now I found that in this row The element exist. Now in that row I will implement another binary search to find if that element
            //really exists in that array or not.
            if (searchRow(matrix, target, mid_row)) {
                cout << "Element found.\n";
                return 0;
            } else {
                cout << "Element not found.\n";
                return 0;
            }
        } else if (target > matrix[mid_row][column - 1]) {
            start_row = mid_row + 1;
        } else {
            end_row = mid_row - 1;
        }
    }
    cout << "Element not found.\n";
    return 0;
}