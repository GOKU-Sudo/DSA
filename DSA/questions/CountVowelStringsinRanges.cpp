class Solution {
public:
      // Function to count vowel strings in given ranges
      vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
            int n = words.size(); // Get the number of words
            vector<int> Prefix(n + 1, 0); // Initialize prefix sum array with zeros
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'}; // Set of vowel characters

            // Calculate prefix sums
            for (int i = 0; i < n; i++) {
                  Prefix[i + 1] = Prefix[i]; // Carry forward the previous prefix sum
                  // Check if the current word starts and ends with a vowel
                  if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                        Prefix[i + 1]++; // Increment the prefix sum if condition is met
                  }
            }

            vector<int> ANS; // Vector to store the results of the queries
            // Process each query
            for (auto& query : queries) {
                  int L = query[0], R = query[1]; // Get the range from the query
                  ANS.push_back(Prefix[R + 1] - Prefix[L]); // Calculate the number of vowel strings in the range
            }

            return ANS; // Return the results
      }
};
