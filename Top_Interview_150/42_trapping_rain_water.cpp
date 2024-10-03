class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n==0) return 0;

        int max = height[0];
        vector<int> ans(n,0);

        for (int i = 1; i < n; i++) {
            if (max <= height[i]) {
                max = height[i];
            }
            else {
                ans[i] = max - height[i];
            }
        }

        max = height[n-1];

        for (int j = n-1; j >=0; j--) {
            if (max <= height[j]) {
                max = height[j];
            }
            if (ans[j] + height[j] > max) {
                ans[j] = max - height[j];
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }
};