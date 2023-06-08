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
    int largest=INT32_MIN;
    for(int i=0;i<n;i++){
        if(a[i] > largest){
            largest=a[i];
        }
    }
    cout<<"Largest no. is :"<<largest;
    return 0;
}