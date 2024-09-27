#include <vector>
#include <limits>
#include <cmath>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> values;
        inorderTraversal(root, values);
        
        int minDiff = std::numeric_limits<int>::max(); // Initialize minDiff to a large value
        for (size_t i = 1; i < values.size(); ++i) {
            minDiff = std::min(minDiff, values[i] - values[i - 1]); // Compare adjacent values
        }
        
        return minDiff;
    }

private:
    void inorderTraversal(TreeNode* node, std::vector<int>& values) {
        if (node == nullptr) return;
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
};

#include <limits>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // Initialize the previous value and the minimum difference
        prev = -1; // This will hold the previous node value during traversal
        minDiff = std::numeric_limits<int>::max(); // Start with the largest possible value
        
        // Perform inorder traversal
        inorderTraversal(root);
        
        return minDiff;
    }

private:
    int prev; // Previous node value
    int minDiff; // Minimum difference found

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        // Traverse left subtree
        inorderTraversal(node->left);
        
        // Process the current node
        if (prev != -1) { // Check if this is not the first node
            minDiff = std::min(minDiff, abs(node->val - prev)); // Update minDiff
        }
        prev = node->val; // Update prev to current node's value

        // Traverse right subtree
        inorderTraversal(node->right);
    }
};
