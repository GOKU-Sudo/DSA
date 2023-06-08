#include<iostream>
#include "2-creatingObject1.cpp"
using namespace std;

class student1{
    int age2;
    int roll2;
    public:
     student1(int a, int b){
        age2=a;
        roll2=b;
     }
     void display2(){
        cout<<age2<<" "<<roll2<<endl;
     }
};

int main(){
    student1 s1(20,10);
    student1 s2(s1);
    s2.display2();
    student1  *s3=new student1(21,11);
    s3->display2();
    student1 s4(*s3);
    student1 *s5=new student1(*s3);
    student1 *s6=new student1(s1);
    return 0;
}