// 1004. Max Consecutive Ones III

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Example 2:
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

#include <vector>
using namespace std;

class Solution {
public:
      int longestOnes(vector<int>& nums, int k) {
            int left = 0; // Left pointer of the window
            int right; // Right pointer of the window
            int maxLength = 0; // Maximum length of subarray with at most k zeroes
            int zeroes = 0; // Count of zeroes in the current window

            int size = nums.size(); // Size of the input array

            // Iterate over the array with the right pointer
            for(right = 0; right < size; right++) {
                  // If the current element is 0, increment the zeroes count
                  if(nums[right] == 0) zeroes++;

                  // If the count of zeroes exceeds k, move the left pointer to the right
                  while(zeroes > k) {
                        if(nums[left] == 0) {
                              zeroes--; // Decrement the zeroes count if the element at left pointer is 0
                        }
                        left++; // Move the left pointer to the right
                  }

                  // Update the maximum length of the subarray
                  maxLength = max(maxLength, right - left + 1);
            }
            return maxLength; // Return the maximum length found
      }
};




//OPTIMIZED CODE --> instead of incrementing left using while, we increment left 1 and keep increment right pointer and left pointer till zeroes<=k and also maxLength is upadted only if zeroes<=k

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int left=0;
//         int right=0;
//         int maxLength=0;
//         int zeroes=0;

//         int size=nums.size();

//         for(right=0;right<size;right++){

//             if(nums[right]==0) zeroes++;

//             if(zeroes>k){
//                 if(nums[left]==0) zeroes--;
//                 left++;
//             }
//             if(zeroes<=k){
//                 maxLength=max(maxLength,right-left+1);
//             }

//         }

//             return maxLength;
//     }
// };
