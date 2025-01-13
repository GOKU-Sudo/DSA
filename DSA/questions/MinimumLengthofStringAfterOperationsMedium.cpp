// 3223. Minimum Length of String After Operations

// You are given a string s.

// You can perform the following process on s any number of times:

//     Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
//     Delete the closest character to the left of index i that is equal to s[i].
//     Delete the closest character to the right of index i that is equal to s[i].

// Return the minimum length of the final string s that you can achieve.

 

// Example 1:

// Input: s = "abaacbcbb"

// Output: 5

// Explanation:
// We do the following operations:

//     Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
//     Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".

// Example 2:

// Input: s = "aa"

// Output: 2

// Explanation:
// We cannot perform any operations, so we return the length of the original string.

class Solution {
public:
      int minimumLength(string s) {
            // Step 1: Count the frequency of each character in the string
            unordered_map<char, int> charFrequencyMap; // Create a map to store the frequency of each character
            for (char currentChar : s) { // Iterate through each character in the string
                  charFrequencyMap[currentChar]++; // Increment the frequency of the current character in the map
            }

            // Step 2: Calculate the number of characters to delete
            int deleteCount = 0; // Initialize the delete count to 0
            for (auto& pair : charFrequencyMap) { // Iterate through each character-frequency pair in the map
                  int frequency = pair.second; // Get the frequency of the current character
                  if (frequency % 2 == 1) { // If frequency is odd
                        // If frequency is odd, delete all except one
                        deleteCount += frequency - 1; // Add (frequency - 1) to the delete count
                  } else { // If frequency is even
                        // If frequency is even, delete all except two
                        deleteCount += frequency - 2; // Add (frequency - 2) to the delete count
                  }
            }

            // Step 3: Return the minimum length after deletions
            return s.length() - deleteCount; // Return the original length minus the delete count
      }
};