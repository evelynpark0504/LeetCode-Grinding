class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int arr_size = nums.size();
        int cnt = 0;
        int i = 1;
        int temp = nums[0];

        for (int j = 1; j < arr_size ; j++) {

            if (temp!=nums[j]) {
                temp = nums[j];
                nums[i] = nums[j];
                cnt = 0;
                i++;
            } else {
                if (cnt < 1){
                    nums[i] = nums[j];
                    cnt++;
                    i++;
                }
            }
        }

        return i;

    }
};