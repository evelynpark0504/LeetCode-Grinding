class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        make_heap(nums.begin(), nums.end());
        int ans;

        for (int i = 1; i <= k; i++) {
            pop_heap(nums.begin(), nums.end());
            ans = nums.back();
            nums.pop_back();
        }
        
        return ans;
    }
};