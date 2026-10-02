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
    // global variable update
    // inorder traversal

public:
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        dfs(root, maxsum);
        return maxsum;
    }
private:
    int dfs(TreeNode* root, int& maxsum){
        if(!root) return 0;
        int leftsum = max(0, dfs(root->left, maxsum));
        int rightsum = max(0, dfs(root->right, maxsum));
        int peaksum = root->val + leftsum + rightsum;
        maxsum = max(maxsum, peaksum);
        return root->val + max(leftsum, rightsum);
    }
};
