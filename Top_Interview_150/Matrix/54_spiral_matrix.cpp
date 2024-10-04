class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int rows = matrix.size(), cols = matrix[0].size();
        int rStart = 0, cStart = 0, rEnd = rows - 1, cEnd = cols - 1;
        vector<int> result;

        while (rStart <= rEnd && cStart <= cEnd) {
            // Traverse from left to right along the top row
            for (int j = cStart; j <= cEnd; ++j) {
                result.push_back(matrix[rStart][j]);
            }
            ++rStart;  // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = rStart; i <= rEnd; ++i) {
                result.push_back(matrix[i][cEnd]);
            }
            --cEnd;  // Move the right boundary left

            // Traverse from right to left along the bottom row (if it's still valid)
            if (rStart <= rEnd) {
                for (int j = cEnd; j >= cStart; --j) {
                    result.push_back(matrix[rEnd][j]);
                }
                --rEnd;  // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if it's still valid)
            if (cStart <= cEnd) {
                for (int i = rEnd; i >= rStart; --i) {
                    result.push_back(matrix[i][cStart]);
                }
                ++cStart;  // Move the left boundary right
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int rStart = 0, rEnd = m-1, cStart = 0, cEnd = n-1;

        while (ans.size() < m*n) {

            for (int j = cStart; j <= cEnd; j++) {
                ans.push_back(matrix[rStart][j]);
            }
            ++rStart;

            if (rStart>rEnd) {
                break;
            }

            for (int i = rStart; i <= rEnd; i++) {
                ans.push_back(matrix[i][cEnd]);
            }
            --cEnd;

            if (cStart>cEnd) {
                break;
            }

            for (int j = cEnd; j >= cStart; j--) {
                ans.push_back(matrix[rEnd][j]);
            }
            --rEnd;

            for (int i = rEnd; i >= rStart; i--) {
                ans.push_back(matrix[i][cStart]);
            }
            ++cStart;

        }

        return ans;
        
    }
};