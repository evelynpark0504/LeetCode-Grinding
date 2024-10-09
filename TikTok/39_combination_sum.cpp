class Solution {
public:
    void multiDp(unordered_map <int, vector<vector<int>>>& dict, int target) {
        for (int i = 1; i <= target/2; i++) {
            if (dict.find(i) != dict.end() && dict.find(target-i) != dict.end()) {
                for (vector<int> l1: dict[i]) {
                    for (vector<int> l2: dict[target-i]) {
                        vector<int> merged = l1;
                        merged.insert(merged.end(), l2.begin(), l2.end());
                        sort(merged.begin(), merged.end());

                        if (dict[target].end() == find(dict[target].begin(), dict[target].end(), merged)) dict[target].push_back(merged);
                        
                    }
                }                
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        if (candidates.size()==1 && candidates[0] > target) return vector<vector<int>>();

        unordered_map<int, vector<vector<int>>> sum_dict;

        for (int num: candidates) {
            sum_dict[num].push_back(vector<int>(1, num));
        }

        if (target==1) {
            if (sum_dict.find(1) != sum_dict.end()) return sum_dict[1];
            else return vector<vector<int>>();
        }

        if (sum_dict.find(1) != sum_dict.end()) sum_dict[2].push_back({1,1});


        for (int i = 3; i <= target; i++) {
            multiDp(sum_dict, i);
        }

        return sum_dict[target];

    }
};

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result, int start) {

        if (target == 0) {
            result.push_back(current);
            return;
        }


        for (int i = start; i < candidates.size(); i++) {
            // If the current candidate exceeds the target, no need to proceed further
            if (candidates[i] > target) break;

            current.push_back(candidates[i]);
            
            backtrack(candidates, target - candidates[i], current, result, i); // `i` allows reusing the same element

            // Backtrack: remove the last element from the current combination
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;

        backtrack(candidates, target, current, result, 0);

        return result;
    }
};