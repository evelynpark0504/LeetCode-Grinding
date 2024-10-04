class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rChar;
        unordered_set<char> cChar;
        unordered_set<char> bChar;

        for (int i=0; i<9; i++) {
            rChar.clear();
            cChar.clear();

            for (int j=0; j<9; j++) {

                if (i%3 == 0 && j%3 == 0) {
                    bChar.clear();
                    for (int n = 0; n < 3; n++) {
                        for (int m = 0; m < 3; m++) {
                            if (bChar.find(board[i+n][j+m]) != bChar.end()) {
                                return false;
                            }
                            if (board[i+n][j+m] != '.') {
                                bChar.insert(board[i+n][j+m]);
                            }
                        }
                    }
                }

                if (rChar.find(board[i][j]) != rChar.end() || cChar.find(board[j][i]) != cChar.end()) {
                    return false;
                }
                
                if (board[i][j] != '.') {
                    rChar.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    cChar.insert(board[j][i]);
                }
                
            }
        }

        return true;

    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 sets for rows, columns, and 3x3 sub-boxes
        vector<unordered_set<char>> rowSets(9), colSets(9), boxSets(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                
                // Skip empty cells
                if (current == '.') continue;

                // Calculate the index for the sub-box
                int boxIndex = (i / 3) * 3 + j / 3;

                // Check if the current value is already present in the row, column, or sub-box
                if (rowSets[i].count(current) || colSets[j].count(current) || boxSets[boxIndex].count(current)) {
                    return false;
                }

                // Insert current value into the respective row, column, and sub-box set
                rowSets[i].insert(current);
                colSets[j].insert(current);
                boxSets[boxIndex].insert(current);
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // We will use three arrays of integers as bitmasks for rows, columns, and boxes.
        int row[9] = {0}, col[9] = {0}, box[9] = {0};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // Check if the cell is filled with a number (skip if it's '.')
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';  // Convert '1'-'9' to 0-8 for easier indexing
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    // Create a bitmask for the current number
                    int mask = 1 << num;

                    // Check if the number has already been seen in the current row, column, or box
                    if (row[i] & mask || col[j] & mask || box[boxIndex] & mask) {
                        return false;
                    }

                    // Mark the number as seen in the current row, column, and box
                    row[i] |= mask;
                    col[j] |= mask;
                    box[boxIndex] |= mask;
                }
            }
        }

        return true;
    }
};