// 1493. Longest Subarray of 1's After Deleting One Element

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

class Solution {
public:
      int longestSubarray(vector<int>& nums) {
            int left = 0;
            int maxLength = 0;
            int size = nums.size();
            int k = 1; // We are allowed to delete at most one element
            int zeroes = 0; // Count of zeroes in the current window

            // Iterate through the array with the right pointer
            for (int right = 0; right < size; right++) {
                  if (nums[right] == 0) {
                        zeroes++; // Increment zero count if the current element is zero
                  }

                  // If the count of zeroes exceeds k, shrink the window from the left
                  while (zeroes > k) {
                        if (nums[left] == 0) {
                              zeroes--; // Decrement zero count if the element at left is zero
                        }
                        left++; // Move the left pointer to the right
                  }

                  // Update the maximum length of the subarray
                  maxLength = max(maxLength, right - left + 1);
            }
            return maxLength - 1; // Subtract 1 to account for the deleted element
      }
};
