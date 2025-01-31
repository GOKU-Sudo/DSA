// Problem Statement

// Given an array A of size N that contains only non-negative integers, find a continuous sub-array that adds to a given number S and return the left and right indexes of that sub-array. In the case of multiple subarrays, return the subarray indexes that come first when moving from left to right.

// Note: Both the indexes in the array should be according to 1-based indexing. You have to return an array list consisting of two elements, left and right. If no such subarray exists, return an array consisting of element -1.
//


#include<bits/stdc++.h>
using namespace std;

vector<int> index(int arr[],int size,int sum){
for(int i=0;i<size;i++){
      int sumTemp=0;
            for(int j=i;j<size;j++){
                  sumTemp=sumTemp+arr[j];
                  if(sumTemp==sum){
                        return {i+1,j+1};
                  }
                  else if(sumTemp>sum){
                        break;
                  }
            }
      }
      return {-1};

}



int main(){
      int size;
      cin>>size;
      int arr[size];
      int sum;
      cin>>sum;
      for(int i=0;i<size;i++){
            cin>>arr[i];
      }

     vector<int> result= index(arr,size,sum);

      for(int i=0;i<2;i++){
            cout<<result[i]<<" ";
      }


      return 0;
}