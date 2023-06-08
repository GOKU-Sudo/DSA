#include<bits/stdc++.h>
using namespace std;

void mergeArray(int x[],int y[],int a[],int s,int e){
      int mid=(s+e)/2;
      int i=s;
      int j=mid+1;
      int k=s;
      while(i<=mid and j<=e){
            if(x[i]<y[j]){
                  a[k]=x[i];
                  i++;
                  k++;
            }
            else{
                  a[k]=y[j];
                  j++;
                  k++;
            }
            
      }
      while(i<=mid){
                  a[k]=x[i];
                  i++;
                  k++;
      }
      while(j<=e){
            a[k]=y[j];
            j++;
            k++;
      }

}

void mergeSort(int a[],int s,int e){
      if(s>=e) return;

      int mid=(s+e)/2;
      // int left=mid;
      // int right=e-mid;
      int x[100], y[100];
      for(int i=0;i<=mid;i++){
            x[i]=a[i];
      }
      for(int i=mid+1;i<=e;i++){
            y[i]=a[i];
      }
      mergeSort(x,s,mid);
      mergeSort(y,mid+1,e);
      mergeArray(x,y,a,s,e);
}

int main(){
      int n;
      cout<<"no of elements :";
      cin>>n;
      int a[n];
      cout<<"Enter the elements :"<<endl;
      int i=0;
      while(i<n){
            cin>>a[i];
            i++;
      }
      mergeSort(a,0,n-1);
      for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
      }
      return 0;
}