#include<iostream>
using namespace std;

int length(char arr[]){
    int count=0;
    for (int i = 0; arr[i]!='\0'; i++){
        count++;
    }
    return count;
}

void reverse(char arr[]){
    int s=0;
    int e=length(arr)-1;
    while (s<e){

        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

int main(){
    char a[]={};
    cout<<"Enter the string :";
    cin.getline(a,200);
    reverse(a);
    cout<<a;
    return 0;
}