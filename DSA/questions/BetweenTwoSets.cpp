#include <bits/stdc++.h>

using namespace std;



int getTotalX(vector<int>a,vector<int>b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int c=0;
    for(int i=a[a.size()-1];i<=b[0];i++){
      int set=1;
        for(int j=0;j<a.size();j++){
            if(i%a[j]==0){
                set=1;
                continue;
            }
            else{
                set=0;
                break;
            }
        }
        if(set==1){
            for(int k=0;k<b.size();k++){
            if(b[k]%i==0){
                set=1;
            }
            else{
                set=0;
                break;
            }
        }
        if(set==1){
            c++;
        }
    }
}
    return c;
}
int main()
{  vector<int>a,b;

   int m,n;
   cin>>m>>n;
   for(int i=0;i<m;i++){
      int x;
      cin>>x;
      a.push_back(x);
   }
  
    for(int j=0;j<n;j++){
        int x;
        cin>>x;
        b.push_back(x);
   }
   cout<<getTotalX(a,b);
}

