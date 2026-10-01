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
        int maxi = 0;
        max_h(root, maxi);
        return maxi;
    }
private:
    int max_h(TreeNode*root, int& maxi){
        if(!root) return 0;
        int l_h = max_h(root->left, maxi);
        int r_h = max_h(root->right, maxi);
        maxi = max(maxi, l_h+r_h); // diameter at each node (hint was that the diameter may not pass through the root, so you could nto run a program that ends at root. hence its a global variable + recursive return)
        return 1+max(l_h, r_h); // what is needed up is the height
    }
};
