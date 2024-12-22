// 1456. Maximum Number of Vowels in a Substring of Given Length

// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

// Example 1:
// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.

// Example 2:
// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.

// Example 3:
// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.

// Constraints:
//     1 <= s.length <= 105
//     s consists of lowercase English letters.
//     1 <= k <= s.length

class Solution {
public:
      int maxVowels(string s, int k) {
            // Initialize current vowel count and maximum vowel count
            int curr = 0, maxVowel;

            // Get the length of the string
            int size = s.length();

            // Define the vowels
            string vowel = "aeiou";

            // Count the number of vowels in the first substring of length k
            for (int i = 0; i < k; i++) {
                  if (vowel.find(s[i]) != string::npos) {
                        curr++;
                  }
            }

            // Set the initial maximum vowel count
            maxVowel = curr;

            // Slide the window over the string
            for (int i = 1; i <= size - k; i++) {
                  // Remove the effect of the character that is sliding out of the window
                  if (vowel.find(s[i - 1]) != string::npos) {
                        curr--;
                  }
                  // Add the effect of the character that is sliding into the window
                  if (vowel.find(s[i + k - 1]) != string::npos) {
                        curr++;
                  }
                  // Update the maximum vowel count
                  maxVowel = max(curr, maxVowel);
            }

            // Return the maximum number of vowels found in any substring of length k
            return maxVowel;
      }
};
