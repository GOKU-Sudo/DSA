// 392. Is Subsequence

// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false

// Constraints:
// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.

class Solution {
public:
      bool isSubsequence(string s, string t) {
            int sizes = s.size(); // Get the size of string s
            int sizet = t.size(); // Get the size of string t

            // If t is smaller than s, s cannot be a subsequence of t
            if (sizet < sizes) return false;

            int s_start = 0; // Pointer for string s
            int s_end = sizes; // End pointer for string s

            int t_start = 0; // Pointer for string t
            int t_end = sizet; // End pointer for string t

            // Iterate through both strings
            while (s_start < s_end && t_start < t_end) {
                  if (s[s_start] == t[t_start]) {
                        // If characters match, move both pointers
                        s_start++;
                        t_start++;
                  } else {
                        // If characters do not match, move pointer of t
                        t_start++;
                  }
            }

            // If we have traversed all characters of s, it is a subsequence of t
            if (s_start == s_end) return true;
            else return false;
      }
};
