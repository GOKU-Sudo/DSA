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
            string vowels = "aeiou"; // String containing all vowels
            int n = s.length(); // Length of the input string
            int count = 0; // Variable to store the maximum number of vowels
            int curr = 0; // Variable to store the current number of vowels in the current window

            // Count the number of vowels in the first window of size k
            for (int i = 0; i < k; i++) {
                  if (vowels.find(s[i]) != string::npos) {
                        curr++;
                  }
            }
            count = curr; // Initialize count with the number of vowels in the first window

            // Slide the window over the string
            for (int i = k; i < n; i++) {
                  if (vowels.find(s[i]) != string::npos) {
                        curr++; // Increment current count if the new character is a vowel
                  }
                  if (vowels.find(s[i - k]) != string::npos) {
                        curr--; // Decrement current count if the character going out of the window is a vowel
                  }

                  count = max(count, curr); // Update the maximum count
            }

            return count; // Return the maximum number of vowels found in any window of size k
      }
};
