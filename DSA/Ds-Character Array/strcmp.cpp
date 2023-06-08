#include<iostream>
#include<cstring>
using namespace std;

int cmp(char str1[], char str2[]){
    if(strlen(str1)==strlen(str2)){
        for(int i=0; i<strlen(str1); i++){
            if(str1[i]==str2[i])
            cout<<0;
            break;
        }
    }
    else if(strlen(str1)<strlen(str2)){
        for (int i=0; i<strlen(str1); i++)
        {
            if(str1[i]<str2[i])
            cout<<1;
            break;
        }      
    }
    else if(strlen(str1)>strlen(str2)){
        for (int i=0; i<strlen(str2); i++)
        {
            if(str1[i]>str2[i])
            cout<<-1;
            break;
        }     
    }
}
int main(){
    char a[]="";
    char b[]="";
    cout<<"Enter words :"<<endl;
    cin>>a>>b;
    cmp(a,b);
    return 0;
}

