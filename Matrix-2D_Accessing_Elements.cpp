#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

//Conventional way: (without using any vector)

// int main(){
//     int matrix[3][3];
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cin>>matrix[i][j];
//         }
//     }
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cout<<matrix[i][j];
//         }
//         cout<<endl;
//     }
// }

//Dynamic Matrix: with vectors
int main(){
    vector<vector<int>>matrix={{1,2,3},{4,5,6,88,99},{11,44,34,65,83}};

    //matrix.size() = row size by default (suppose 1st row in total 3)
    //matrix[i].size() = in first row how many elements (suppose in 1st row here 3 elements)
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}