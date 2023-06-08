#include<iostream>
using namespace std;
class fraction{
      int num,deno;
      public:
         fraction(int num,int deno){
           this->num=num;
            this->deno=deno; // we use this operator to use same name of property and parameter
         }
         void print(){
            cout<<num<<"/"<<deno<<endl; //we can also use this-> num and deno
         }
         fraction add(fraction const &f) const{
            int lcm=deno*f.deno;
            int x=lcm/deno;
            int y=lcm/f.deno;
            int num1=x*num+y*f.num;
            // num=num1;
            // deno=lcm;
            fraction fnew(num1,lcm);
            fnew.simplify();
            return fnew;
         }
         fraction operator+(fraction const &f) const{
            int lcm=deno*f.deno;
            int x=lcm/deno;
            int y=lcm/f.deno;
            int num1=x*num+y*f.num;
            // num=num1;
            // deno=lcm;
            fraction fnew(num1,lcm);
            fnew.simplify();
            return fnew;
         }
         void simplify(){
            int gcd=1;
            int j=min(num,deno);
            for(int i=1; i<=j;i++){
               if(num%i==0 && deno%i==0){
                  gcd=i;
               } // there is inbuilt fn for gcd is __gcd(a,b) under the algorithm header
            }
            num=num/gcd;
            deno=deno/gcd;
         }
         fraction multiply(fraction const &f) {
            num=num*f.num; // using this is optional 
            deno=deno*f.deno;
            fraction fnew(num,deno);
            fnew.simplify();
            return fnew;
         }
         fraction operator*(fraction const &f) const{
            int n =num*f.num; // using this is optional 
            int d=deno*f.deno;
            fraction fnew(n,d);
            fnew.simplify();
            return fnew;

         }
         bool operator==(fraction const &f) const{
            return (num==f.num && deno==f.deno);
            
         }
      //    void operator++(){
      //       num=num+deno;
      //       simplify();
      //    }
      //    fraction operator++(){
      //       num=num+deno;
      //       simplify();
      //       return *this; // returnin the content , not the address
      //    }
          fraction& operator++(){
            num=num+deno;
            simplify();
            return *this; 
         }
};

int main(){
      fraction f1(10,2);
      fraction f2(15,4);
      f1.print();
      f2.print();
      // ++f1;    //part 1
      // f1.print(); //part 1
      // fraction f3=++f1;  //part 2
      // f1.print(); //part 2
      // f3.print(); //part 2

      fraction f3=++(++f1);
      f1.print();
      f3.print();
      return 0;
}