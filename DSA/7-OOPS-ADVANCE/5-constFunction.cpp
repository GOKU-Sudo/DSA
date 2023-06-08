#include<iostream>
using namespace std;

class fraction{
      int num,deno;
      public:
         fraction(){   
         }
         fraction(int num,int deno){
           this->num=num;
            this->deno=deno; 
         }
         void print(){
            cout<<num<<"/"<<deno<<endl; 
         }
         int getNum(){
            return num;
         }
         int getDeno(){
            return deno;
         }
         int getDeno() const{
            return deno;
         }
         int getNemo() const{
            return num;
         }
         int setNum(int num){
            this->num=num;
         }
         int setDeno(int deno){
            this->deno=deno;
         }
         void add(fraction const &f){
            int lcm=deno*f.deno;
            int x=lcm/deno;
            int y=lcm/f.deno;
            int num1=x*num+y*f.num;
            num=num1;
            deno=lcm;
            simplify();
         }

         void simplify(){
            int gcd=1;
            int j=min(num,deno);
            for(int i=1; i<=j;i++){
               if(num%i==0 && deno%i==0){
                  gcd=i;
               } 
            }
            num=num/gcd;
            deno=deno/gcd;
         }
         void multiply(fraction &f){
            num=num*f.num; 
            deno=deno*f.deno;
         }
};

int main(){  //like const vriable, const object can be made too
      fraction f1(10,2);
      fraction f2(15,4);
      fraction const f3; // const object

      // cout<<f3.getNum()<<" "<<f3.getDeno();
      // f3.setNum(30);  ---->both above and below line will not work because it const obeject
      //                  and const object can not access any properties that makes changes in program
      // only const fun can be accessed by const object
      // const fun--> that does not make changes in program

      cout<<f3.getNemo()<<" "<<f3.getDeno();
      return 0;
}