#include<iostream>
using namespace std;

int main(){
    char a[]={};
    cout<<"Enter :";
    cin.getline(a,100,'o');
    //third parameter is optional that is delimiter, by default it new line character
    cout<<a;
    return 0;
}