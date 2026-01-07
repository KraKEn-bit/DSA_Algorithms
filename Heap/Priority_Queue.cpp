#include<iostream>
#include<vector>

using namespace std;

int parent(int i){
    return (i-1)/2;
}

int leftchild(int i){
    return (2*i)+1;
}

int rightchild(int i){
    return (2*i)+2;
}

void shiftup(int i, vector<int>& arr){
    while(i>0 && arr[parent(i)] < arr[i]){
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }
}

void shiftdown(int i,vector<int>& arr){
    int maxindx = i;
    int l = leftchild(i);
    int r = rightchild(i);

    if(i<arr.size() && arr[l]>arr[i]){
        maxindx = l;
    }
    if(i<arr.size() && arr[r]>arr[i]){
        maxindx = r;
    }
    if(i!=maxindx){
        swap(arr[parent(i)],arr[i]);
        shiftdown(maxindx,arr);
    }
}

void insert(int val,vector<int>& arr){
    arr.push_back(val);
    shiftup(arr.size()-1 , arr);
}


int pop(vector<int> &arr){
    int size = arr.size();
    if(size==0){
        return -1;
    }
    int result = arr[0];
    swap(arr[0],arr[size-1]);
    arr.pop_back();
    shiftdown(0,arr);
    return result;
}

int getMax(vector<int> &arr){
    return arr[0];
}

void printHeap(vector<int> &arr){
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> pq;

    insert(45,pq);
    insert(30,pq);
    insert(14,pq);
    insert(18,pq);
    insert(20,pq);
    insert(38,pq);
    insert(50,pq);
    
    cout<<"Priority queue after inserts: ";
    printHeap(pq);


    cout<<"Max element: "<<getMax(pq)<<endl;

    pop(pq);
    cout<<"Priority queue after poping: ";
    printHeap(pq);
}