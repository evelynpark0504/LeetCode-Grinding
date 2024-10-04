class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; // left pointer
        int subSum = 0; // current subarray sum
        int subLength = nums.size() + 1; // start with an invalid length
        int arrSize = nums.size();

        for (int j = 0; j < arrSize; ++j) {
            subSum += nums[j]; // add nums[j] to the current window sum

            // Shrink the window from the left as long as the sum is >= target
            while (subSum >= target) {
                subLength = min(subLength, j - i + 1); // update min length
                subSum -= nums[i]; // remove nums[i] from the sum
                ++i; // move left pointer
            }
        }

        // If subLength was updated, return it, otherwise return 0
        return subLength == nums.size() + 1 ? 0 : subLength;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0); // Prefix sum array of size n+1

        // Step 1: Compute the prefix sum
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int minLength = n + 1; // Start with an invalid length (infinity)

        // Step 2: Iterate through the array and use binary search
        for (int j = 1; j <= n; ++j) {
            // We need to find the smallest i such that prefix[j] - prefix[i] >= target
            int toFind = prefix[j] - target;
            
            // Use binary search to find the leftmost index `i` such that prefix[i] <= toFind
            auto it = lower_bound(prefix.begin(), prefix.begin() + j, toFind);
            
            if (it != prefix.begin() + j) {
                int i = it - prefix.begin();
                minLength = min(minLength, j - i);
            }
        }

        // If minLength was updated, return it, otherwise return 0
        return minLength == n + 1 ? 0 : minLength;
    }
};