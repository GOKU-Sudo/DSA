
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

class Solution {
public:
      double findMaxAverage(vector<int>& nums, int k) {
            // Initialize max_avg to the lowest possible double value
            double max_avg = numeric_limits<double>::lowest();
            // Initialize the window sum to 0
            double w_sum = 0;
            // Get the size of the input array
            int n = nums.size();
            // Initialize the start index of the window
            int start = 0;

            // Iterate through the array
            for (int i = 0; i < n; i++) {
                  // Add the current element to the window sum
                  w_sum += nums[i];

                  // Check if the current window size is equal to k
                  if ((i - start + 1) == k) {
                        // Calculate the average of the current window
                        double avg = w_sum / k;
                        // Update max_avg if the current average is greater
                        max_avg = max(avg, max_avg);
                        // Subtract the element at the start of the window from the window sum
                        w_sum -= nums[start];
                        // Move the start index to the right
                        start += 1;
                  }
            }

            // Return the maximum average found
            return max_avg;
      }
};
