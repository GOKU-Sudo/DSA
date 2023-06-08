#include<iostream>
#include "student.cpp"
using namespace std;
// initialisation  initialise the const properties and reference properties  at the time of memory allocation

int main(){
      student s1(100,10);
      s1.age=10;
      // s1.rollnumber=100;
      cout<<s1.age<<endl<<s1.rollnumber;
      return 0;
}