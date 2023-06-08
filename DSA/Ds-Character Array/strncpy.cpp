#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[5]="hell";
    char b[]="hi";
    strncpy(a,b,4);
    cout<<a<<endl;
    cout<<sizeof(a);
    char x[]="abc";
    cout<<sizeof(x);
    return 0;
}