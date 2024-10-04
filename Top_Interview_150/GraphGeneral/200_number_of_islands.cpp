class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0; 
        int n = grid[0].size();
        vector<vector<bool>> vmap(m, vector<bool>(n, false));
        int ans = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if (grid[i][j] == '1' && !vmap[i][j]){
                    ++ans;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    vmap[i][j] = true;

                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();

                        // Check and enqueue all valid neighbors
                        if (x - 1 >= 0 && grid[x - 1][y] == '1' && !vmap[x - 1][y]){
                            q.push({x - 1, y});
                            vmap[x - 1][y] = true;
                        }
                        if (x + 1 < m && grid[x + 1][y] == '1' && !vmap[x + 1][y]){
                            q.push({x + 1, y});
                            vmap[x + 1][y] = true;
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1' && !vmap[x][y - 1]){
                            q.push({x, y - 1});
                            vmap[x][y - 1] = true;
                        }
                        if (y + 1 < n && grid[x][y + 1] == '1' && !vmap[x][y + 1]){
                            q.push({x, y + 1});
                            vmap[x][y + 1] = true;
                        }
                    }
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    void isIsland(vector<vector<char>>& grid,int x,int y,vector<vector<int>>& visited){
        if(!visited[x][y]){
            visited[x][y] = 1;
            int dx[4] = {+1,-1,0,0};
            int dy[4] = {0,0,-1,+1};

            for(int i=0; i<4; i++){
                int row = x + dx[i];
                int col = y + dy[i];
                if(row < grid.size() && row >=0 && col < grid[0].size() && col>=0 && grid[row][col] == '1'){
                    isIsland(grid,row,col,visited);
                }
            }

            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int cnt = 0;

        for(int i=0; i < n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    isIsland(grid,i,j,visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};