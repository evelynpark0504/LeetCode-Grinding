class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int lp = 0, rp = 0;
        int maxLen = 0;
        int n = s.length();

        while (rp < n) {
            if (charSet.find(s[rp]) == charSet.end()) {
                charSet.insert(s[rp]);
                maxLen = max(maxLen, rp - lp + 1);
                rp++;
            }
            else {
                charSet.erase(s[lp]);
                lp++;
            }
        }

        return maxLen;
    }
};