#include <bits/stdc++.h>
using namespace std;
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      int i = 0, j = 0, k = 0;
      vector<int> v1;
      while (i < nums1.size() && j < nums2.size())
      {
            if (nums1[i] < nums2[j])
                  i++;
            else if (nums1[i] > nums2[j])
                  j++;
            else
            {
            
                  v1.push_back(nums1[i]);
                  ++i, ++j;
            }
      }
      return v1;
}

int main()
{
      vector<int> v1 = {4, 9, 5};
      vector<int> v2 = {9, 4, 9, 8, 4};
      vector<int> v3 = intersect(v1, v2);
      for (auto i : v3)
      {
            cout << i << " ";
      }
      return 0;
}