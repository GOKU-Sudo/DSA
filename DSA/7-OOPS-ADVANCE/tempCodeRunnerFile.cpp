#include<iostream>
using namespace std;

class student{
      int age;
      char *name;
      public:
        student(int age, char *name){
            this->age=age;
            this->name=name;
        }
        void display(){
            cout<<age<<" "<<name<<endl;
        }
};

int main(){    //copying only address is called shallow copyl, generally we should avoid this

      char name[]="hello";
      student s1(20,name);
      s1.display();
      name[1]='i';
      student s2(20,name);
      s2.display();
      s1.display();
      return 0;
}