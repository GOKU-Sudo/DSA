// 394. Decode String

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

 

// Constraints:

//     1 <= s.length <= 30
//     s consists of lowercase English letters, digits, and square brackets '[]'.
//     s is guaranteed to be a valid input.
//     All the integers in s are in the range [1, 300].

class Solution {
      public String decodeString(String s) {
            // Create a stack to keep track of counts
            Stack<Integer> counts = new Stack<>();
            // Create a stack to keep track of strings
            Stack<String> strings = new Stack<>();

            // Initialize the current string as empty
            String currentString = "";
            // Initialize the count as 0
            int count = 0;

            // Iterate over each character in the input string
            for (char c : s.toCharArray()) {
                  // If the character is a digit
                  if (Character.isDigit(c)) {
                        // Update the count
                        count = count * 10 + (c - '0');
                  }
                  // If the character is an opening bracket
                  else if (c == '[') {
                        // Push the current count to the counts stack
                        counts.push(count);
                        // Push the current string to the strings stack
                        strings.push(currentString);
                        // Reset the count
                        count = 0;
                        // Reset the current string
                        currentString = "";
                  }
                  // If the character is a closing bracket
                  else if (c == ']') {
                        // Store the current string in a temporary variable
                        String temp = currentString;
                        // Pop the last string from the strings stack
                        currentString = strings.pop();
                        // Pop the last count from the counts stack
                        int timesRepeated = counts.pop();

                        // Append the temporary string to the current string timesRepeated times
                        for (int i = 0; i < timesRepeated; i++) {
                              currentString = currentString + temp;
                        }
                  }
                  // If the character is a letter
                  else {
                        // Append the character to the current string
                        currentString = currentString + c;
                  }
            }
            // Return the decoded string
            return currentString;
      }
}
