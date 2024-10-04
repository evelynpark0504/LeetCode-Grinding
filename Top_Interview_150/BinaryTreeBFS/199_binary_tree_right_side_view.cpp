 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if (!root) {
            return answer;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == size - 1) {
                    answer.push_back(node->val);
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return answer;
    }
};

class Solution {
public:
    void rightTravel(TreeNode* node, int level, int& prev, vector<int>& values) {
        if (node == nullptr) {
            return;
        }

        // If this is the first node we're visiting at this depth, add it to the result
        if (level > prev) {
            values.push_back(node->val);
            prev = level;  // Update prev to the current level
        }

        // Traverse the right subtree first
        rightTravel(node->right, level + 1, prev, values);
        
        // Traverse the left subtree next
        rightTravel(node->left, level + 1, prev, values);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> values;
        int prev = -1;  // Initialize prev to -1 to indicate no levels processed yet

        // Call the right traversal function starting from root at level 0
        rightTravel(root, 0, prev, values);

        return values;
    }
};