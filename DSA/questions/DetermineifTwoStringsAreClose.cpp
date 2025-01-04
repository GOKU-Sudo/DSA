// 1657. Determine if Two Strings Are Close

// Two strings are considered close if you can attain one from the other using the following operations:
//     Operation 1: Swap any two existing characters.
//         For example, abcde -> aecdb
//     Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
//         For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.
// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

// Example 1:
// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"

// Example 2:
// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

// Example 3:
// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"

class Solution {
public:
      bool closeStrings(string word1, string word2) {
            // If the lengths of the two strings are not equal, they cannot be close
            if(word1.length() != word2.length()) return false;

            // Frequency vectors to count occurrences of each character in both strings
            vector<int> freq1(26, 0);
            vector<int> freq2(26, 0);

            // Presence vectors to check if a character is present in the strings
            vector<bool> present1(26, false);
            vector<bool> present2(26, false);

            int i = 0;

            // Iterate through each character in the strings
            while(i < word1.length()) {
                  // Increment the frequency count for the current character in both strings
                  freq1[word1[i] - 'a']++;
                  freq2[word2[i] - 'a']++;

                  // Mark the current character as present in both strings
                  present1[word1[i] - 'a'] = true;
                  present2[word2[i] - 'a'] = true;
                  i++;
            }

            // If the presence vectors are not equal, the strings cannot be close
            if(present1 != present2) return false;

            // Sort the frequency vectors
            sort(freq1.begin(), freq1.end());
            sort(freq2.begin(), freq2.end());

            // If the sorted frequency vectors are equal, the strings are close
            return freq1 == freq2;
      }
};
