#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Convert 2D coordinates to 1D based on the Boustrophedon pattern.
    int getBoardValue(const vector<vector<int>>& board, int pos) {
        int n = board.size();
        int r = n - 1 - (pos - 1) / n;  // Row is flipped (bottom to top)
        int c = (pos - 1) % n;          // Column index depends on the row direction
        
        // If it's an odd row (from bottom perspective), reverse the column index
        if (((n - 1 - r) % 2) == 1) {
            c = n - 1 - c;
        }
        
        return board[r][c];
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;

        // BFS setup
        queue<pair<int, int>> q;  // (current square, number of moves)
        q.push({1, 0});           // Start at square 1 with 0 moves

        vector<bool> visited(target + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            
            // Try all moves with a dice roll (1 to 6)
            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > target) break;  // Beyond the last square
                
                // Check if there's a snake or ladder at this square
                int boardVal = getBoardValue(board, next);
                if (boardVal != -1) {
                    next = boardVal;  // Move to the destination of the snake/ladder
                }
                
                // If we reach the target square, return the number of moves
                if (next == target) {
                    return moves + 1;
                }

                // If not visited, add to the queue
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        // If we exit the loop without reaching the target, return -1
        return -1;
    }
};

int main() {
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };

    Solution sol;
    cout << sol.snakesAndLadders(board) << endl;  // Example output: 4

    return 0;
}