class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n==1) {
            return 0;
        }

        for (int i=0; i <n; i++) {
            if (i-1 < 0) {
                if (nums[i] > nums[i+1]) {
                    return i;
                } 
            } else if (i+1 == n) {
                if (nums[i] > nums[i-1]) {
                    return i;
                    }
            } else {
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                    return i;
                }
            }
        }

        return -1;
        
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[mid] > nums[mid+1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};