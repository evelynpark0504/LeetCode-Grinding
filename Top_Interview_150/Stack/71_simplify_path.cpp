class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string segment;
        stack<string> segments;

        // Split string by '/'
        while (std::getline(ss, segment, '/')) {
            if (segment!="" && segment!=".") {
                segments.push(segment);
            }
            
        }

        string ans = "";
        int upper_stack = 0;

        while (!segments.empty()) {
            auto top = segments.top();
            segments.pop();

            if (top=="..") {
                ++upper_stack;
            } else if (!top.empty()){
                if(upper_stack>0) {
                    --upper_stack;
                } else {
                    ans = "/" + top + ans;
                }
            }
            
        }

        return ans.empty() ? "/" : ans;        
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string segment;
        stack<string> segments;

        // Split string by '/'
        while (std::getline(ss, segment, '/')) {
            if (segment=="" || segment==".") {
                continue;
            } else if (segment=="..") {
                if (!segments.empty()) {
                    segments.pop();
                }
            } else segments.push(segment);
        }

        if (segments.empty()) return "/";

        string ans = "";

        while (!segments.empty()) {
            auto top = segments.top();
            segments.pop();

            ans = "/" + top + ans;
        }

        return ans;        
    }
};