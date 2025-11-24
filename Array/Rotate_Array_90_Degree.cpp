#include<iostream>
#include<string>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> result(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[j][n-1-i] = matrix[i][j];
        }
    }

    cout<<endl;
    cout<<"90 degree Rotated matrix is: "<<endl;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

}