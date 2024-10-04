class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s==t) {
            return true;
        }

        unordered_map<char, char> dict;
        vector<char> dup_char;
        vector<char> used_val;

        for (int i = 0; i < s.length(); i++) {
            if (dict.find(s[i]) == dict.end()) {
                if (find(dup_char.begin(), dup_char.end(), t[i]) != dup_char.end()) {
                    return false;
                }
                dict[s[i]] = t[i];
                dup_char.push_back(t[i]);
            } else {
                if (dict[s[i]] != t[i]) return false;
            }
        }

        return true;
    }

};