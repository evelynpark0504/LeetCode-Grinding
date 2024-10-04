class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int l = digits.size() - 1;
        digits[l] += 1;

        for (int i = digits.size() - 1; i > 0; i--) {
            if (digits[i] != 10) {
                return digits;
            } else {
                digits[i] = 0;
                digits[i-1] += 1;
            }
        }

        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};