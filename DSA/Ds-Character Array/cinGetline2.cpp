#include<iostream>
using namespace std;

int main(){
    char a[]={};
    cout<<sizeof(a);
    cout<<"Enter sentence :";
    cin.getline(a,4);
    cout<<a;
    return 0;
}