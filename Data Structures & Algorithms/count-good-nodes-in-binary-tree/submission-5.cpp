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
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
private: 
    int dfs(TreeNode* root, int maxseen){
        if(!root) return 0;
        int res = 0;
        if(root->val >= maxseen) res = 1; // pre-order traversal, check root, update the count, then check children below for lower values
        maxseen = max(maxseen, root->val);
        int l = dfs(root->left, maxseen);
        int r = dfs(root->right, maxseen);
        return res + l + r;
    }
};
