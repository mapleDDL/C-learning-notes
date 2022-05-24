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
    bool isUnivalTree(TreeNode* root) {
        return mapleRecursion(root, root->val);
    }

    bool mapleRecursion(TreeNode* node, int val) {
        if (node == nullptr) { return true; }
        if (node->val != val) { return false; }

        return mapleRecursion(node->left, val) && mapleRecursion(node->right, val);
    }
};