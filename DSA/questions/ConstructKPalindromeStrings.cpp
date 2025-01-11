// 1400. Construct K Palindrome Strings

// Example 1:

// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

// Example 2:

// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.

// Example 3:

// Input: s = "true", k = 4
// Output: true
// Explanation: The only possible solution is to put each character in a separate string.

// Constraints:

//     1 <= s.length <= 105
//     s consists of lowercase English letters.
//     1 <= k <= 105

class Solution {
public:
      bool canConstruct(string s, int k) {
            // Handle edge cases: if the length of s is less than k, return false
            if (s.length() < k) return false;
            // If the length of s is equal to k, return true
            if (s.length() == k) return true;

            // Initialize frequency array to count occurrences of each character
            vector<int> freq(26);
            // Initialize oddCount to count characters with odd frequencies
            int oddCount = 0;

            // Increment the value of the index corresponding to the current character
            for (auto& chr : s) freq[chr - 'a']++;

            // Count the number of characters that appear an odd number of times in s
            for (int i = 0; i < 26; i++) {
                  if (freq[i] % 2 == 1) {
                        oddCount++;
                  }
            }

            // Return true if the number of odd frequencies is less than or equal to k
            return (oddCount <= k);
      }
};
