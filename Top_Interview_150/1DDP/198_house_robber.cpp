class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        if(nums.size() == 3) {
            return max(nums[0]+nums[2], nums[1]);
        }

        vector<int> ans(nums.size()+1, 0);
        ans[1] = nums[0];
        ans[2] = nums[1];
        ans[3] = max(nums[0]+nums[2], nums[1]);

        for (int i=4; i<=nums.size(); i++) {
            ans[i] = max(ans[i-2], ans[i-3]) + nums[i-1];
        }

        return *max_element(ans.begin(), ans.end());

    }
};