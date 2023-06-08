#include<iostream>
using namespace std;

void prefix(char arr[]){
    for (int  e = 0; arr[e]!='\0'; e++)
    {
        for (int s = 0; s<=e; s++)
        {
            cout<<arr[s];
        }
       cout<<endl; 
    }
    
}

int main(){
    char a[]={};
    cout<<"Enter the word :";
    cin>>a;
    prefix(a);
    return 0;
}