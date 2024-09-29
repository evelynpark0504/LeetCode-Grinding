class Solution {
public:

    map<string, vector<string>> dict;

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size()==0) {
            return ans;
        }

        dict["2"] = {"a", "b", "c"};
        dict["3"] = {"d", "e", "f"};
        dict["4"] = {"g", "h", "i"};
        dict["5"] = {"j", "k", "l"};
        dict["6"] = {"m", "n", "o"};
        dict["7"] = {"p", "q", "r", "s"};
        dict["8"] = {"t", "u", "v"};
        dict["9"] = {"w", "x", "y", "z"};
        
        if (digits.size()==1) {
            return dict[digits];
        }

        backTraking(digits, 1);

        return dict[digits];

    }

    void backTraking(string& digits, int target) {

        if (digits.size()==target) {
            return;
        }

        string prev = digits.substr(0, target);
        string curr(1, digits[target]);
        string comb_key = digits.substr(0, target+1);

        for (string s : dict[prev]) {
            for (string r: dict[curr]) {
                dict[comb_key].push_back(s+r);
            }
        }

        backTraking(digits, target + 1);

    }
};