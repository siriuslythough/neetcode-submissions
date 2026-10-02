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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // first you seach the tree and then find the root under which you are supposed to sit (that must be enmpty though
        // see the place you should occupy. if its occupied descend lower, until the first leaf that you can occupy)

        // new keyword allows you to add a new node!
        if(!root) root = new TreeNode(val);
        if(val < root->val){
            if (!root->left) root->left = new TreeNode(val);
            else root->left = insertIntoBST(root->left, val);
        }
        if(val>root->val){
            if (!root->right) root->right = new TreeNode(val);
            else root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};