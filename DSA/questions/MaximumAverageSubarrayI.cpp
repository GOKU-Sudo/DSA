
// 643. Maximum Average Subarray I

// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10^-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

// Constraints:
// n == nums.length
// 1 <= k <= n <= 10^5
// -10^4 <= nums[i] <= 10^4

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
      double findMaxAverage(vector<int>& nums, int k) {
            double curr = 0, maxSum;
            int size = nums.size();

            // Calculate the sum of the first 'k' elements
            for(int i = 0; i < k; i++) {
                  curr = curr + nums.at(i);
            }

            // Initialize maxSum with the sum of the first 'k' elements
            maxSum = curr;

            // Slide the window of size 'k' across the array
            for(int i = 1; i <= size - k; i++) {
                  // Update the current sum by subtracting the element that is left behind
                  // and adding the new element in the window
                  curr = curr - nums.at(i - 1) + nums.at(i + k - 1);
                  // Update maxSum if the current sum is greater
                  maxSum = max(maxSum, curr);
            }

            // Return the maximum average...
            return maxSum / k;
      }
};