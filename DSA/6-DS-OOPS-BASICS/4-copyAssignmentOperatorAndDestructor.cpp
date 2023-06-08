#include<iostream>
#include "studentCLass.cpp"
using namespace std;

int main(){
    student s1(20,300);
    student s2(10,400);
    student *s3=new student(30,300);
    s2=s1; //copy assignment operator
    *s3=s1;
    s2=*s3;
    s1.display();
    s2.display();
    s3->display();
    delete s3;
    return 0;
}