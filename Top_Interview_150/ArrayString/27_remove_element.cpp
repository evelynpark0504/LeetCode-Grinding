class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        int temp = nums.size() - 1;

        while (i <= temp) {
            
            if (nums[i] == val) {
                k++;
                nums[i] = nums[temp];  // Replace current element with the last one
                nums[temp] = -1;       // Optional: Mark the last element as removed
                temp--;                // Reduce the effective size by one

            } else {
                i++;  // Move forward only if the current element is not `val`
            }

        }

        return temp+1;
    }
};