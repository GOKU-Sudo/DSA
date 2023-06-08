#include <iostream>
#include<cstring>
using namespace std; 
int main() {
    // Write C++ code here
    char *c=new char[10];
    char *c1=new char;
    char *c2=new char(12);
    char c4[10];
    char c5[2];
    cout<<sizeof(c1);
    cout<<sizeof(c5);

    return 0;
}