#include<iostream>
using namespace std;

void swap(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
  
}

int main(){
    int a,b;
    cout<<"Enter the numbers :";
    cin>>a>>b;
    swap(a,b);
    cout<<a<<" "<<b;
    return 0;
}