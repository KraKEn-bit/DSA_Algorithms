#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of containers: ";
    cin>>n;
    vector<int>container(n);
    for(int i=0;i<n;i++){
        cin>>container[i];
    }
    int maxContainer=0;
    for(int left_bottom=0;left_bottom<n;left_bottom++){
        for(int right_bottom=left_bottom+1;right_bottom<n;right_bottom++){
            int height=min(container[left_bottom],container[right_bottom]);
            int width=right_bottom-left_bottom;
            int area=height*width;
            maxContainer=max(maxContainer,area);
        }
    }
    cout<<"The maximum amount of water a container can store is: "<<maxContainer;
    return 0;
}

//Here I am taking 2 ends of a container for each iteration. Right and Left which will hold the water.
//Then consider the fact that the water will be held in the container upto the smaller end if one of the ends is lesser than the other meaning the Y axis.
//That's why for height I took the minimum value. and width will be the difference between the indexes meaning the X axis.


//If the constraints are in <=10^5 it won't work as it is O(n^2) we need optimized approach.