class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        int rb = 0, cb = 0, sb = 0;

        if (s.length() % 2 != 0) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char ele = s[i];

            if (ele == '('|| ele == '{' || ele == '[') {
                temp.push(ele);
            }
            if (ele == ')') {
                if (temp.empty() || temp.top() != '(') {
                    return false;
                }
                temp.pop();
            }
            if (ele == '}') {
                if (temp.empty() || temp.top() != '{') {
                    return false;
                }
                temp.pop();
            }
            if (ele == ']') {
                if (temp.empty() || temp.top() != '[') {
                    return false;
                }
                temp.pop();
            }      
        }

        if (!temp.empty()) {
            return false;
        }
        return true; 
    }
};