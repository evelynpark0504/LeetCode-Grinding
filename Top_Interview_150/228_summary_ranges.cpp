class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size()==0) {
            return ans;
        }

        string ans_ele = to_string(nums[0]);

        if (nums.size()==1) {
            ans.push_back(ans_ele);
            return ans;
        }

        int prev = 0;
        
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1] + 1) {
                if (i-1!=prev) {
                    ans_ele += "->";
                    ans_ele += to_string(nums[i-1]);
                }

                ans.push_back(ans_ele);
                
                prev = i;
                ans_ele = to_string(nums[i]);
            }

            if (i == nums.size()-1) {
                if (prev==i) {
                    ans.push_back(ans_ele);
                } else {
                    ans_ele += "->";
                    ans_ele += to_string(nums[i]);
                    ans.push_back(ans_ele);
                }
            }
        }

        return ans;
    }
};