#include<iostream>
using namespace std;

int length(char character[]){
    int count=0;
    for(int i=0; character[i]!=0;i++){
        count++;
    }
    return count;
}

int main(){
    char a[]="";
    cout<<"Enter the stirng :";
    cin>>a;
    cout<<length(a);
    return 0;
}