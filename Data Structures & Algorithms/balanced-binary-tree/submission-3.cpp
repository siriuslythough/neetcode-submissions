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
    bool isBalanced(TreeNode* root) {
        // get the height at each node, and check the difference
        if(!root) return true;
        int l_h = h(root->left);
        int r_h = h(root->right);
        bool thisnode = (l_h-r_h<=1 && l_h-r_h>=-1);
        bool leftchild = isBalanced(root->left);
        bool rightchild = isBalanced(root->right);
        return (thisnode && leftchild && rightchild); 
    }
private:
    int h(TreeNode* root){
        if(!root) return 0;
        int l = h(root->left);
        int r = h(root->right);
        return 1 + max(l,r);
    }
};
