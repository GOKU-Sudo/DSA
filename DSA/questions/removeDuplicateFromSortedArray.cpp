#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int temp[nums.size()],j=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[j++]=nums[i];
            }
        }
        nums[j++]=nums[nums.size()-1];
        return j;
     
    }

int main(){
      vector<int>v1;
      int n;
      cin>>n;
      while(n--){
            int x;
            cin>>x;
            v1.push_back(x);
      }
      cout<<removeDuplicates(v1)<<endl;
      for(auto i: v1) cout<<i<<" ";
      return 0;
}

