#include<iostream>
#include "2-creatingObject1.cpp"
using namespace std;

int main(){
    student s1, *s2;
    s2= new student;
    s1.setAge(20);
    s2->setAge(30);
    s1.display();
    s2->display();
    return 0;
}