#include<bits/stdc++.h>
using namespace std;

string removeReverse(string S) { // wrong
        int i=0;
        int j=1;
        unordered_map<char,int>freq;
        for(int i=0;i<S.size();i++)
        {
            freq[S[i]]++;
        }
       while(true){
        if(S.size()==1) break;

        for(int i=0;i<S.size()-1;i++){
            if(freq[S[i]]==freq[S[i+1]]) break;
        }
           if(S[i]!=S[j]){
               j++;
           }
           if(S[i]==S[j]){
               freq[S[i]]--;
               S.erase(i,1);
               reverse(S.begin(), S.end()); 
               i=0;
               j=1;
           }
       }
       return S;
    }

int main(){
      string str;
      cin>>str;
      cout<<removeReverse(str);
      return 0;
}