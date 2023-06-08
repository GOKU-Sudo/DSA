#include<iostream>
using namespace std;

class student{
    int rn;
    int age;
    public:
    void setAge(int a){
        age=a;
    }
    void display(){
        cout<<age<<endl;
    }

};