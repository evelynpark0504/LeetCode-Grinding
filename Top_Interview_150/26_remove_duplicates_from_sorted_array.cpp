class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int temp = nums[0];

        for (int j = 1; j < n; j++) {
            if (nums[j] != temp) {
                temp = nums[j];
                nums[i] = temp;
                i++;
            }
        }
        return i;
    }
};
