class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int sIdx = -1;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0]==target || matrix[i][n-1]==target) {
                return true;
            } else {
                if (matrix[i][0]<target && matrix[i][n-1]>target) {
                    sIdx = i;
                }
            }
        }

        if (sIdx == -1) {
            return false;
        }

        for (int i=0; i<n; i++) {
            if (matrix[sIdx][i] == target) {
                return true;
            }
        }

        return false;
        
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lower = 0;
        int upper = matrix.size() * matrix[0].size()-1;
        int i = 0;
        while(lower <= upper) {
            int iteratorCol = (lower + (upper - lower)/2)%matrix[0].size();
            int iteratorRow = (lower + (upper - lower)/2)/matrix[0].size();
            if(matrix[iteratorRow][iteratorCol] == target) {
                return 1;
            } else if(matrix[iteratorRow][iteratorCol] > target) {
                upper = (iteratorCol) + (iteratorRow)*matrix[0].size()-1;
            } else {
                lower = (iteratorCol) + (iteratorRow)*matrix[0].size()+1;
            }
            ++i;
        }
        return 0;
    }
};