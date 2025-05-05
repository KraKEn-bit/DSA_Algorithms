//This problem is for "If first integer of each row is not greater than the last integer of the previous row!!

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

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

    int start = 0, end = column - 1;
    while (start < row && end >= 0) {
        if (target == matrix[start][end]) {
            cout << "Target exists!";
            return 0;
        } else if (target < matrix[start][end]) {
            end--;
        } else {
            start++;
        }
    }
    
    cout << "Target not found!" << endl;
    return 0;
}
