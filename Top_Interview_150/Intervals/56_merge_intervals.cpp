class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;  // Handles empty or single interval cases
        }

        // Sort intervals by the start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> current_interval = intervals[0];  // Start with the first interval

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval overlaps with the next one, merge them
            if (current_interval[1] >= intervals[i][0]) {
                // Extend the end of the current interval
                current_interval[1] = max(current_interval[1], intervals[i][1]);
            } else {
                // No overlap, add the current interval to the answer and start a new one
                ans.push_back(current_interval);
                current_interval = intervals[i];
            }
        }

        // Add the last interval
        ans.push_back(current_interval);

        return ans;
    }
};