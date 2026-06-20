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
        // DFS -> increment count until new node>=last seen max
        return dfs(root, root->val);
    }
private:
    int dfs(TreeNode* node, int maxseen){
        if (node==nullptr) return 0;
        int res = 0;
        if(node->val>=maxseen) res = 1;
        maxseen = max(maxseen, node->val);
        return res + dfs(node->right, maxseen) + dfs(node->left, maxseen);
    }
};
