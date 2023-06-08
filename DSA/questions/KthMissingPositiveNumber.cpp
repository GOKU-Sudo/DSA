#include<bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
        int count=0;int store=0;
        int i=0;int j=1;
        while(true){
            if(arr[i]==j){
                i++;
                j++;
            }
            else if(arr[i]!=j){
                store=j;
                count++;
                j++;
            }

            if(count==k){
                break;
            }

        }
        return store;
    }

int main(){
      vector<int>v1={1,2,3,4};int k=2;
      cout<<findKthPositive(v1,k);
      return 0;
}