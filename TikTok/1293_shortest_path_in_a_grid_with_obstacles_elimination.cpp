class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if (m==1&&n==1) {
            if (k >= grid[m-1][n-1]) {
                return 0;
            } else return -1;
        }

        queue<tuple<int, int, int, int>> q;
        vector<vector<int>> visit_map(m, vector<int>(n, -1));

        q.push({0,0,k,0});
        visit_map[0][0] = true;

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [x, y, k, move] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x+dx[i];
                int newY = y+dy[i];

                if (newX>-1 && newX<m && newY>-1 && newY<n) {
                    if (newX==m-1 && newY==n-1 && k >= grid[newX][newY]) return move+1;

                    int newK = k - grid[newX][newY];

                    if (newK>=0 && visit_map[newX][newY]<newK) {
                        q.push({newX, newY, newK, move+1});
                        visit_map[newX][newY] = newK;
                    }
                }
            }
        }      

        return -1;

    }
};