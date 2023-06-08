#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int s,int e){
      int pivotElement=a[e];
      int i=s;
      int j=s;
      while(j<=e-1){
            if(a[j]<pivotElement){
                  swap(a[i],a[j]);
                  i++;
                  j++;
            }
            else{
                  j++;
            }
      }
      swap(a[i],a[e]);
      return i; //pivot element position
}

void quickSort(int a[],int s,int e){
      if(s>=e) return;//base condition
      int pivot=partition(a,s,e);
      quickSort(a,s,pivot-1);
      quickSort(a,pivot+1,e);
}

int main(){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++){
            cin>>a[i];
      }
      quickSort(a,0,n-1);
      for(int i=0;i<n;i++){
            cout<<a[i];
      }
      return 0;
}