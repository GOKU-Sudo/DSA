#include<iostream>
using namespace std;

class student{
      public:
      int roll;
      int age; //whenever we create a class object, only non static gets copied to object
      // non static properties can be accessed only by class
     static int totalStudents; // total no. of students present
     // static properties only belong to class not to objects
     student(){
      totalStudents++;
     }
     static int getTotalstudents(){ //like static member , static member can also be made
//      static fn can only be accessed by class  and can only access static data member and can only access static func

//static fn do not have this keyword
      return totalStudents;
     }
     

};

//static properties can only be accessed by using :: method
//can be initialised only outside the class

int student::totalStudents=0;

// int main(){
//     student s1;
//     cout<<s1.roll<<" "<<s1.age<<" "<<student::totalStudents<<endl;
//     student s2;
//     s2.totalStudents=20;// compiler will allow but it's logically incorrect
//     cout<<s1.totalStudents;// compiler will allow but it's logically incorrect
//       return 0;
// }

int main(){
      student s1,s2,s3,s4,s5;
      cout<<student::totalStudents<<endl;
      cout<<student::getTotalstudents;
      

}