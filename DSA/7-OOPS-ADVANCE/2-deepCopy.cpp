#include<iostream>
#include<cstring>
using namespace std;
class student{
      int age;   //deep copy is making a new array and copy the content into new th array
      char *name;
      public:
        student(int age, char *name){
            this->age=age;
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
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