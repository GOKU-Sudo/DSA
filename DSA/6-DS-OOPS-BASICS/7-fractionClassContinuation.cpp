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
         void add(fraction const &f){
            int lcm=deno*f.deno;
            int x=lcm/deno;
            int y=lcm/f.deno;
            int num1=x*num+y*f.num;
            num=num1;
            deno=lcm;
            // f.num=-1 --> aim is to avoid this
            // we only want reference variable to read data, not change
            // so we use const reference variable
            simplify();
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
         void multiply(fraction &f){
            num=num*f.num; // using this is optional 
            deno=deno*f.deno;
         }
};

int main(){
      fraction f1(10,2);
      fraction f2(15,4);
      f1.add(f2);
      f1.print();
      f2.print();
      f1.multiply(f2);
      f1.print();
      f2.print();
      return 0;
}