#include<iostream>
using namespace std;

int main(){
    char name[100];
    cout<<"Enter your name :";
    cin>>name;
    cout<<"Your name is :"<<name<<endl;
    name[1]='\0';
    // name[3]='d';
    // name[4]='e';
    cout<<name;
    return 0;
}