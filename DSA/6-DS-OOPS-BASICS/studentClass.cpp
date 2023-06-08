#include<iostream>
using namespace std;
class student{
    int age;
    int roll;
    public:
      student(int a, int b){
        age=a;
        roll=b;
      }
      void display(){
        cout<<age<<" "<<roll<<endl;
      }
      ~ student(){
        cout<<"hi"<<endl;
      }
};

