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
};

int main(){
      fraction f1(10,2);
      fraction f2(15,4);
      fraction f3=f1.add(f2);
      // fraction f4=f1.multiply(f2);
      f1.print();
      f2.print();
      f3.print();
      // our aim is to use plus,multiply and == operator on object for ex- f1+f2 using operator overloading
      fraction f5=f1+f2;
      fraction f6=f1*f2;
      f5.print();
      f6.print();
      // f4.print();
      if(f1==f2)
      cout<<"equal";
      else
      cout<<"not equal";
      cout<<endl;
      if(f1==f1)
      cout<<"equal";
      else
      cout<<"not equal";
      // we use by reference to avoid copy cons
      // we use const to avoid illegal changes
      return 0;
}