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
    for (int i=0; i<(n);n--)
    {
        cout<<a[n-1]<<" ";
    }
    
    return 0;
}