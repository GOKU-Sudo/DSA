#include <bits/stdc++.h>
using namespace std;
//
//

void merge(vector<int> &arr, int m, vector<int> &arr2, int n)
{
      int i = m - 1, j = n - 1;
      int k = m + n - 1;
      while (j >= 0 and i >= 0)
      {
            if (arr[i] < arr2[j])
                  arr[k--] = arr2[j--];
            else
                  arr[k--] = arr[i--];
      }
      while (j >= 0)
            arr[k--] = arr2[j--];
      for (auto i : arr)
            cout << i << " ";
}

int main()
{
      vector<int> a = {1, 2, 3, 0, 0, 0};
      vector<int> b = {2, 5, 6};
      merge(a, 3, b, 3);
      return 0;
}