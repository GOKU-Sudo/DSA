#include<bits/stdc++.h>
using namespace std;

      long long distinctNames(vector<string>& ideas) {
        int size=ideas.size();
        set<string> v1;
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-1;j++){
                string s1=ideas[i];
                string s2=ideas[j];
                swap(s1[0],s2[0]);
                if((ideas[i]==s1 and ideas[j]==s2)) continue;
                v1.insert(s1+" "+s2);       
            }
        }
      //   for(auto i: v1)cout<<i<<endl;
      //   cout<<endl;
        return v1.size();
    }

int main(){
      vector<string> v1;
      int n=4;
      while(n--){
            string str;
            cin>>str;
            v1.push_back(str);
      }
      cout<<distinctNames(v1);
      return 0;
}