  
// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray


// You are given an array of integers nums. Return the length of the longest
// subarray
// of nums which is either
// strictly increasing
// or
// strictly decreasing
// .

 

// Example 1:

// Input: nums = [1,4,3,3,2]

// Output: 2

// Explanation:

// The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

// The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

// Hence, we return 2.

// Example 2:

// Input: nums = [3,3,3,3]

// Output: 1

// Explanation:

// The strictly increasing subarrays of nums are [3], [3], [3], and [3].

// The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

// Hence, we return 1.

// Example 3:

// Input: nums = [3,2,1]

// Output: 3

// Explanation:

// The strictly increasing subarrays of nums are [3], [2], and [1].

// The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

// Hence, we return 3.

 

// Constraints:

//     1 <= nums.length <= 50
//     1 <= nums[i] <= 50

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 163.4K
// Submissions
// 250K
// Acceptance Rate
// 65.3%
// Topics
// Array
// Companies
// Discussion (144)
// 💡 Discussion Rules

// 1. Please don't post any solutions in this discussion.

// 2. The problem discussion is for asking questions about the problem or for sharing tips - anything except for solutions.

// 3. If you'd like to share your solution for feedback and ideas, please head to the solutions tab and post it there.
// No comments yet.
// Copyright ©️ 2025 LeetCode All rights reserved
// 6121 Online
// 1
// 2
// 3
// 4
// 5
// 6
// Saved
// nums =
// [1,4,3,3,2]
// 1
// 2
// 3
// [1,4,3,3,2]
// [3,3,3,3]
// [3,2,1]

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // Track current lengths of increasing and decreasing sequences
        int incLength = 1, decLength = 1;
        int maxLength = 1;

        // Iterate through array comparing adjacent elements
        for (int pos = 0; pos < nums.size() - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                // If next element is larger, extend increasing sequence
                incLength++;
                decLength = 1;  // Reset decreasing sequence
            } else if (nums[pos + 1] < nums[pos]) {
                // If next element is smaller, extend decreasing sequence
                decLength++;
                incLength = 1;  // Reset increasing sequence
            } else {
                // If elements are equal, reset both sequences
                incLength = 1;
                decLength = 1;
            }

            // Update max length considering both sequences
            maxLength = max(maxLength, max(incLength, decLength));
        }
        return maxLength;
    }
};