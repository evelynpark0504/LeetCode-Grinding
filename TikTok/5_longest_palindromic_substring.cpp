class Solution {
public:
    bool isPalindrome(string s) {
        int lp = 0;
        int rp = s.length()-1;

        while (rp>lp) {
            if (s[rp]!=s[lp]) {
                return false;
            }
            ++lp;
            --rp;
        }

        return true;
    }

    string longestPalindrome(string s) {
        if (s.length()==1 || isPalindrome(s)) return s;

        int maxVal = -1;
        string ans;

        for (int i=0; i<s.length()-1; i++) {
            for (int j=s.length()-1; j>=i+1; j--) {
                if (s[i] == s[j]) {
                    string str = s.substr(i, j - i + 1);
                    if (isPalindrome(str) && j-i+1 > maxVal) {
                        maxVal = j-i+1;
                        ans = str;
                    }
                }
            }
        }

        return ans.length()==0? ans += s[0] : ans;

    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s; // If the string has 1 or no characters, it's a palindrome

        // Create a DP table where dp[i][j] means whether s[i..j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;    // Start index of the longest palindrome
        int maxLength = 1; // Length of the longest palindrome found so far

        // Base cases: Single character substrings are always palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Base case: Two consecutive equal characters are palindromes
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;      // Update start of the longest palindrome
                maxLength = 2;  // Update max length to 2
            }
        }

        // Check for substrings longer than 2 characters
        for (int len = 3; len <= n; ++len) {   // len is the length of the substring
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;  // j is the end index of the substring

                // Check if the current substring s[i..j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;

                    // Update the longest palindrome found
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, maxLength);
    }
};