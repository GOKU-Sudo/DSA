#include<bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[],int size){
      int isSorted=0; // this is added to check that if array is already sorted;
      for(int i=0;i<size-1;i++){                     // by default bubble sort is not adaptive for sorted array but it is stable
                                                     // for every array,so we have to make changes in bubble sort for sorted array to run in O(n)
            isSorted=1;
            cout<<"Working of pass "<<i+1<<endl;
            for(int j=0;j<size-1;j++){
                  if(arr[j]>arr[j+1]){
                        swap(arr[j],arr[j+1]);
                        isSorted=0;
                  }
            }
            if(isSorted) return;
      }
}

int main(){

      int n;
      cin>>n;
      int arr[n];

      for(int i=0;i<n;i++){
            cin>>arr[i];
      }
      bubbleSort(arr,n);
       for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
      }

      
      return 0;
}