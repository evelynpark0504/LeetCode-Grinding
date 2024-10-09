class Solution {
public:
    bool canCross(vector<int>& stones) {

        if (stones.size()==2&&stones[1] == 1) return true;
        if (stones[1] != 1) return false;

        int n = stones.size();

        unordered_map<int, int> stone_map;
        for (int i = 0; i < n; i++) {
            stone_map[stones[i]] = i;  // Map stone position to its index
        }

        int move[] = {-1, 0, 1};

        queue<pair<int, int>> q;
        unordered_map<int, unordered_set<int>> visited;

        q.push({1, 1});
        visited[1].insert(1);

        while (!q.empty()) {
            auto [idx, prev_jump] = q.front();
            q.pop();

            // Explore all 3 possible jump distances (prev_jump - 1, prev_jump, prev_jump + 1)
            for (int i = 0; i < 3; i++) {
                int jump = prev_jump + move[i];
                if (jump <= 0) continue; // The jump must be positive.

                int newPos = stones[idx] + jump;

                if (newPos == stones[n - 1]) return true;

                if (stone_map.find(newPos) != stone_map.end()) {
                    int newIndex = stone_map[newPos];
                    if (visited[newIndex].find(jump) == visited[newIndex].end()) {
                        q.push({newIndex, jump});
                        visited[newIndex].insert(jump);
                    }
                }
            }
        }

        return false;
    }
};