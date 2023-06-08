#include<iostream>
using namespace std;

void printArray(int a[][5],int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int b[][5]={ {1,2,3} ,
    {5,5},{12},{7,45,89,44,12}};

    printArray(b,2,5);
    return 0;
}
//we can't pass whole 2D array as a parameter in function