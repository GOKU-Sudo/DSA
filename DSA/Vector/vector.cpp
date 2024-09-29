#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int>* v1 =new vector<int>(); // dynamic creation of vector
      vector<int> v2; // static creation of vector
      v2.push_back(10);
      v2.push_back(20);
      v2.push_back(30);
      cout<<v2[0]<<endl;

      v2[1]=200;

      v2[3]=40;
      v2[4]=50;

      for(int i:v2){
            cout<<i<<" ";
      }
      cout<<endl;
      cout<<v2[3];
      cout<<endl;


      // cout<<v2.at(4);
      // cout<<v2.at(5);          // at function first check if index valid or not
                                //but [] jumps to that index and print whatever garbage value is present
      // cout<<v2.at(6);   
      
      for(int i=0;i<v2.size();i++){
            cout<<v2[i]<<" ";
      }
      cout<<endl;

      cout<<v2.size();
      cout<<endl;
      v2.pop_back();
        for(int i=0;i<v2.size();i++){
            cout<<v2[i]<<" ";
      }

      cout<<endl;

      // never use square bracket for putting element becuase it does not double the size of vector
      //only pushback fn do so

      cout<<v2.capacity();
        cout<<endl;
      //different btw capacity and size is that size will give no of element in vecotr
      // but capacity will give the capacity upto which it can hold
      // initially capacity and size is zero



      vector<int> v4(5); // by default initialised with zero
    for(int i:v4){
            cout<<i<<" ";
      }
      cout<<endl;

      vector<int> v3(5,-2); // initialize with -2
         for(int i:v3){
            cout<<i<<" ";
      }
            cout<<endl;

sort(v2.begin(),v2.end());
  for(int i:v2){
            cout<<i<<" ";
      }

      cout<<endl;


      return 0;

      
}