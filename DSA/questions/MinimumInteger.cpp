#include<bits/stdc++.h>
using namespace std;
int minimumInteger(int N, vector<int> &A) {
        // code here
        long long sum=0;
        long long min=INT_MAX;
        for(long long i=0;i<N;i++){
            sum=sum+A[i];
        }
        
        for(long long i=0;i<N;i++){
            if(sum<=(long) (long) N* (long) (long)A[i] && A[i]<min) min=A[i];
        }
        return min;
    }

int main(){
      long long n;
      cin>>n;
      vector<int>v1;
      for(long long i=0;i<n;i++){
            cin>>v1[i];
      }
      cout<<minimumInteger(n,v1);
      return 0;
}