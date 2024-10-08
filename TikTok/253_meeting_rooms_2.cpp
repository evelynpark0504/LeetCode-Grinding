class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {

        if (intervals.size()==1) {
            return 1;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0]==b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> occupy;
        occupy.push(intervals[0][1]);

        for (int i = 1; i < intervals.size(); i++) {
            if (occupy.top() <= intervals[i][0]) {
                occupy.pop();
            }
            occupy.push(intervals[i][1]);
        }
        return occupy.size();
    }
};