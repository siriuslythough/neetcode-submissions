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
        // DFS -> but you definitely need a helper function
        // because you need to pass a maxseen_in_the_path to every node you visit to check if its greater
        return dfs(root, INT_MIN);
    }
private:
    int dfs(TreeNode* node, int maxseen){
        if (!node) return 0;
        int res = 0;
        // preorder traversal: you check node first, update your measures on it, then check children
        if(node->val >= maxseen) res = 1;
        maxseen = max(maxseen, node->val); // update maxseen so that you can compare if followed node
                                           // is largest seen between node and root or not
        return res + dfs(node->right, maxseen) + dfs(node->left, maxseen);
    }
};
