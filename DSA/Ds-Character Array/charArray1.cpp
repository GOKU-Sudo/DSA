#include<iostream>
using namespace std;

int main(){
    char name[100];
    cout<<"Enter your name :";
    cin>>name;
    cout<<"Your name is :"<<name<<endl;
    name[4]='h';
    cout<<name[4]<<endl;
    cout<<name;
    return 0;
}