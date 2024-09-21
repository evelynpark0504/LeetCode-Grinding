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