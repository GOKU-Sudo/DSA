#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    };
    int smallest=INT32_MAX;
    for(int i=0;i<n;i++){
        if(a[i] < smallest){
            smallest=a[i];
        }
    }
    cout<<"smallest no. is :"<<smallest;
    return 0;
}