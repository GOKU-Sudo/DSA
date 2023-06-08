#include<iostream>
using namespace std;

int main(){
    int a;
    cout<<"Enter the number of elements :";
    cin>>a;
    int b[a];
    for(int i=0; i<a; i++){
        cin>>b[i];
    };
    int i=0;
    int sum=0;
    while(i<a){
        sum=sum+b[i];
        i++;
    };
    cout<<sum;
    return 0;
}