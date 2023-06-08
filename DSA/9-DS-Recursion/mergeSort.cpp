#include<bits/stdc++.h>
using namespace std;

void mergeArray(int a[],int s,int mid,int e){
      int i=s;
      int j=mid+1;
      int k=s;
      int b[e+1];
      while(i<=mid and j<=e){
            
            if(a[i]<a[j]){
                  b[k]=a[i];
                  i++;
                  k++;
            }
            else{
                  b[k]=a[j];
                  j++;
                  k++;
            }
          
      }
      while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
      }
      while(j<=e){
            b[k]=a[j];
            j++;
            k++;
      }
      for(int i=s;i<=e;i++){
            a[i]=b[i];
      }
}

void mergeSort(int a[],int s,int e){
      if(s>=e) return; //base condition
      // if(s<e){
      int mid=(s+e)/2;
      mergeSort(a,s,mid);
      mergeSort(a,mid+1,e);
      mergeArray(a,s,mid,e);
      // }
}

int main(){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++){
            cin>>a[i];
      }
      mergeSort(a,0,n-1);
      for(int i=0;i<n;i++){
            cout<<a[i];
      }
      return 0;
}