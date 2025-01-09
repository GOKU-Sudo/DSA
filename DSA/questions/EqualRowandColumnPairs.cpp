// 2352. Equal Row and Column Pairs

// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

// Example 1:

// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]

// Example 2:

// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]

class Solution {
public:
      int equalPairs(vector<vector<int>>& grid) {
            int count = 0; // Initialize count of equal pairs to 0
            int size = grid.size(); // Get the size of the grid (number of rows/columns)

            vector<vector<int>> rows(size); // Vector to store rows of the grid
            vector<vector<int>> columns(size); // Vector to store columns of the grid

            for(int i = 0; i < size; i++) {
                  rows[i] = grid[i]; // Copy each row of the grid to the rows vector
            }

            for(int j = 0; j < size; j++) {
                  vector<int> col; // Temporary vector to store a column
                  for(int i = 0; i < size; i++) {
                        col.push_back(grid[i][j]); // Copy each element of the column to the temporary vector
                  }
                  columns[j] = col; // Copy the temporary vector to the columns vector
            }

            for(int j = 0; j < size; j++) {
                  for(int k = 0; k < size; k++) {
                        if(rows[j] == columns[k]) count++; // If a row is equal to a column, increment the count
                  }
            }

            return count; // Return the total count of equal pairs
      }  
};
