/*

Best Sightseeing Pair

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
Example 2:

Input: values = [1,2]
Output: 2

*/



class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        if (n < 2) return values[0] + values[1] + 0 - 1; 
        vector<int> suffixMax(n);
        suffixMax[n - 1] = values[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], values[i] - i);
        }
        int maxScore = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            maxScore = max(maxScore, values[i] + i + suffixMax[i + 1]);
        }

        return maxScore;
    }
};