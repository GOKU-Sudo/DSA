#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
      vector<vector<int>> major;
      for (int i = 0; i < sizeof(nums) - 2; i++)
      {
            int j = i + 1;
            int k=j+1;
            if ((nums[i] != nums[j]) && (nums[i] != nums[k]) && (nums[j] != nums[k]) &&(nums[i]+nums[j]+nums[k]==0))
            {
                  vector<int> v1;
                  v1.push_back(nums[i]);
                  v1.push_back(nums[j]);
                  v1.push_back(nums[k]);

                  major.push_back(v1);
            }
      }
      return major;
}

int main()
{
      int x;
      vector<int> v1;
      for(int i=0;i<6;i++){
            cin>>x;
            v1.push_back(x);
      }
      cout<<sizeof(threeSum(v1));
      return 0;
}