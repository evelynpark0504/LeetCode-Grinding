class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int temp = m-1;
        int temp2 = n-1;

        if (m==0) {
            for (int j=0; j<n; j++){
                nums1[j] = nums2[j];
            }
            return;
        }

        if (n==0) {
            return;
        }

        for (int i=m+n-1; i>=0; i--) {
            if (temp2 < 0) {
                break;
            }
            if (temp < 0 || nums1[temp] <= nums2[temp2]) {
                nums1[i] = nums2[temp2];
                temp2-=1;
            } else {
                nums1[i] = nums1[temp];
                temp-=1;
            }
        }

    }
     
};