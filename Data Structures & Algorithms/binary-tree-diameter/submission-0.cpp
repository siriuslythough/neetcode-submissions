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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh = maxh(root->left);
        int rh = maxh(root->right);
        int d = lh+rh;
        int subtree_d = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(subtree_d, d);
    }
private:
    int maxh(TreeNode* root){
        if(root==nullptr) return 0;
        int h = max(maxh(root->left), maxh(root->right));
        return h+1;
    }
};
