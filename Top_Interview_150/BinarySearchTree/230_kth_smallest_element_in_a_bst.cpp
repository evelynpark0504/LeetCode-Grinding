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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return -1;
        }
        vector<int> values;
        inorderTraversal(root, values);

        return values[k-1];        
    }

    void inorderTraversal(TreeNode* node, vector<int>& values) {
        if (node == nullptr) return;
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
};