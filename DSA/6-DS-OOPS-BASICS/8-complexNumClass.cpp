#include<iostream>
using namespace std;

class complexNum{
      int real,img;
      public:
         complexNum(int real, int img){
            this->real=real;
            this->img=img;
         }
         void get(){
            if(img<0)
            cout<<real<<img<<"i"<<endl;
            else
            cout<<real<<"+"<<img<<"i"<<endl;
         }
         void add(complexNum c2){
            real=real+c2.real;
            img=img+c2.img;
         }
         void multiply(complexNum c2){
            real=(real*c2.real)-(img*c2.img);
            img=(real*c2.img)+(c2.real*img);
         }
};
int main(){
      complexNum c1(10,20);   
      complexNum c2(12,40);
      c1.add(c2);
      c1.get();
      c1.multiply(c2);
      c1.get();   
      return 0;
}