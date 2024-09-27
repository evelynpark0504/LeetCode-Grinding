/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void checkBST(TreeNode* node, long& prev, bool& check) {
        if (node==nullptr) {
            return;
        }
        checkBST(node->left, prev, check);
        if (prev >= node->val) {
            check = false;
            return;
        } else {
            prev = node->val;
        }
        checkBST(node->right, prev, check);
    }

    bool isValidBST(TreeNode* root) {
        if (root==nullptr) {
            return true;
        } else if (root->left==nullptr&&root->right==nullptr) {
            return true;
        }

        long prev = numeric_limits<long>::min();
        bool check = true;

        checkBST(root, prev, check);
        
        return check;
    }
};