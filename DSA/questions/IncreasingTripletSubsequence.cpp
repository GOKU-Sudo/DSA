// 334. Increasing Triplet Subsequence

// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

// Example 1:
// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.

// Example 2:
// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.

// Example 3:
// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

class Solution {
public:
      bool increasingTriplet(vector<int>& nums) {
            // Initialize two variables to store the smallest and second smallest values
            int first = INT_MAX, second = INT_MAX;
            
            // Iterate through the array
            for (int val : nums) {
                  // Update the smallest value if the current value is smaller or equal
                  if (val <= first) {
                        first = val; 
                  } 
                  // Update the second smallest value if the current value is smaller or equal
                  // but greater than the smallest value
                  else if (val <= second) {
                        second = val; 
                  } 
                  // If we find a value greater than both the smallest and second smallest values,
                  // it means we have found an increasing triplet
                  else {
                        return true; 
                  }
            }
            // If no increasing triplet is found, return false
            return false; 
      }
};