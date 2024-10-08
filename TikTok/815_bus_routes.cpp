class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source==target) return 0;

        unordered_map<int, vector<int>> hash_map;

        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                hash_map[routes[i][j]].push_back(i);
            }
        }

        queue <pair<int,int>> q;
        unordered_set<int> visited_stop;
        unordered_set<int> visited_bus;

        q.push({source, 0});
        visited_stop.insert(source);

        while(!q.empty()) {
            auto [curr_stop, visit_cnt] = q.front();
            q.pop();

            for (int bus: hash_map[curr_stop]) {
                if (visited_bus.count(bus)==0) {
                    visited_bus.insert(bus);

                    for(int stop: routes[bus]) {
                        if (stop==target) return visit_cnt+1;
                        if (visited_stop.count(stop)==0) {
                            visited_stop.insert(stop);
                            q.push({stop, visit_cnt+1});
                        }
                    }
                }

            }
        }

        return -1;
    }
};