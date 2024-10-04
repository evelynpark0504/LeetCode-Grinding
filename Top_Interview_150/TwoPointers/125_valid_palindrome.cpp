class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned_s;

        for (char c : s) {
            if (isalnum(static_cast<unsigned char>(c))) {
                cleaned_s += tolower(static_cast<unsigned char>(c));
            }
        }

        int str_len = cleaned_s.length();
        int str_idx = str_len / 2;

        for (int i=0; i < str_idx; i++) {
            if (cleaned_s[i] != cleaned_s[str_len-i-1]) {
                return false;
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Directly compare characters without multiple conversions
            char leftChar = tolower(s[left]);
            char rightChar = tolower(s[right]);

            if (leftChar != rightChar) {
                return false;
            }

            // Move both pointers
            left++;
            right--;
        }

        return true;
    }
};
