// 724. Find Pivot Index

// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

 

// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.

// Example 3:

// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0

class Solution {
public:
      int pivotIndex(vector<int>& nums) {
            // Get the size of the input vector
            int size = nums.size();
            
            // Create vectors to store the cumulative sums from the left and right
            vector<int> leftSum(size);
            vector<int> rightSum(size);

            // Initialize the first element of rightSum with the first element of nums
            rightSum[0] = nums[0];
            // Initialize the last element of leftSum with the last element of nums
            leftSum[size - 1] = nums[size - 1];

            // Calculate the cumulative sum from the left
            for (int i = 1; i < size; i++) {
                  rightSum[i] = rightSum[i - 1] + nums[i];
            } 
            
            // Calculate the cumulative sum from the right
            for (int j = size - 2; j >= 0; j--) {
                  leftSum[j] = leftSum[j + 1] + nums[j];
            } 
            
            // Find the pivot index where left sum equals right sum
            for (int i = 0; i < size; i++) {
                  if (leftSum[i] - rightSum[i] == 0) return i;
            }
            
            // Return -1 if no pivot index is found
            return -1;
      }
};