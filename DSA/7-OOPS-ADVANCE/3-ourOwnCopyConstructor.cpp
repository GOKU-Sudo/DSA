#include<iostream>
#include<cstring>
using namespace std;
class student{
      int age;   
      public:
      char *name;
      student(student const &s){
            this->age=s.age;
            this->name==new char[strlen(s.name)+1];
            strcpy(this->name,s.name);
      }
        student(int age, char *name){
            this->age=age;
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
        }
        void display(){
            cout<<age<<" "<<name<<endl;
        }
};

int main(){    
      char name[]="hello";
      student s1(20,name);
      s1.display();
      student s2(s1);
      s1.name[0]='i';
      s1.display();
      s2.display();
      // name[1]='i';
      // student s2(20,name);
      // s2.display();           //inbuilt copy constructor makes shallow copy
      // s1.display();         // whenever we have dynamic array as a data memeber we should make our own copy cons to avoid shallow copy by 
                              // inbuilt copy construtor
      return 0;
}