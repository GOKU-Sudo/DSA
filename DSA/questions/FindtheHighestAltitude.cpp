// 1732. Find the Highest Altitude

// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

 

// Example 1:

// Input: gain = [-5,1,5,0,-7]
// Output: 1
// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

// Example 2:

// Input: gain = [-4,-3,-2,-1,4,3,2]
// Output: 0
// Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.


class Solution {
public:
      int largestAltitude(vector<int>& gain) {
            int size = gain.size(); // Get the size of the gain vector

            vector<int> prefixSum(size + 1); // Create a prefixSum vector of size+1
            prefixSum[0] = gain[0]; // Initialize the first element of prefixSum with the first element of gain

            for (int i = 1; i < size; i++) { // Loop through the gain vector starting from the second element
                  prefixSum[i] = prefixSum[i - 1] + gain[i]; // Calculate the prefix sum for each element
            }

            int highestAltitude = *max_element(prefixSum.begin(), prefixSum.end()); // Find the maximum element in the prefixSum vector
            return highestAltitude; // Return the highest altitude
      }
};
