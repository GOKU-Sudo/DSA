#include<iostream>
#include "1-creatingObjects1.cpp"
using namespace std;


int main(){
    student s1,s2,s3;
    s1.rn=21;
    s1.age=20;

    student *s4=new student;
    (*s4).rn=1;
    s4->age=34;

    cout<<s1.rn<<" "<<s4->age;
    return 0;
}