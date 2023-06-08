#include<bits/stdc++.h>
using namespace std;

int fact(int n){
      if(n==0 or n==1) return 1; // base step
       
      int smallAns= fact(n-1); //2nd step assumption
      int ans=n* smallAns; // calculation step like proof step in PMI
       return ans;
}

int main(){
      int n;
      cin>>n;
      cout<<fact(n);
      return 0;
}
