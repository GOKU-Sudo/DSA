// 1207. Unique Number of Occurrences

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// Example 1:
// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

// Example 2:
// Input: arr = [1,2]
// Output: false

// Example 3:
// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]

class Solution {
public:
      bool uniqueOccurrences(vector<int>& arr) {
            set<int> s1; // Set to store unique occurrence counts
            unordered_map<int, int> map; // Map to store the count of each element
            for(int i: arr) { // Iterate through each element in the array
                  if(map[i]) map[i]++; // If element is already in the map, increment its count
                  else map[i] = 1; // If element is not in the map, add it with count 1
            }

            for(auto i: map) { // Iterate through the map
                  if(s1.count(i.second) > 0) return false; // If the occurrence count is already in the set, return false
                  s1.insert(i.second); // Insert the occurrence count into the set
            }

            return true; // If all occurrence counts are unique, return true
      }
};
