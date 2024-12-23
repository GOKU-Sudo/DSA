// 11. Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1

class Solution {
public:
      int maxArea(vector<int>& height) {
            int size = height.size(); // Get the size of the height array
            int i = 0; // Initialize the left pointer
            int j = size - 1; // Initialize the right pointer
            int maxValue = INT_MIN; // Initialize the maximum value to the smallest integer

            // Loop until the two pointers meet
            while (i < j) {
                  // Calculate the height of the container (the shorter line)
                  int yaxis = min(height[i], height[j]);
                  // Calculate the width of the container
                  int xaxis = abs(i - j);
                  // Calculate the area of the container
                  int ans = yaxis * xaxis;
                  // Update the maximum value if the current area is larger
                  maxValue = max(ans, maxValue);

                  // Move the pointers to try and find a larger container
                  if (height[i] < height[j]) {
                        i++;
                  } else if (height[i] > height[j]) {
                        j--;
                  } else {
                        i++;
                        j--;
                  }
            }
            return maxValue; // Return the maximum area found
      }
};
