// 283. Move Zeroes

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:

// Input: nums = [0]
// Output: [0]


class Solution {
public:
      void moveZeroes(int[] nums) {
            int j = 0; // Initialize a pointer j to keep track of the position to place the next non-zero element
            int i = 0; // Initialize a pointer i to iterate through the array

            while (i < nums.length) { // Loop through the array
                  if (nums[i] == 0) { // If the current element is zero
                        i++; // Move to the next element
                  } else { // If the current element is non-zero
                        nums[j] = nums[i]; // Move the non-zero element to the position pointed by j
                        j++; // Increment j to the next position
                        i++; // Move to the next element
                  }
            }

            while (j < nums.length) { // After all non-zero elements are moved, fill the rest of the array with zeros
                  nums[j] = 0; // Set the current position to zero
                  j++; // Move to the next position
            }
      }
}
