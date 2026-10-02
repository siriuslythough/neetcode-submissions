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
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
private:
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto leftpair = dfs(root->left);
        auto rightpair = dfs(root->right);
        int withroot = root->val + leftpair.second + rightpair.second;
        int withoutroot = max(leftpair.first, leftpair.second) + max(rightpair.first, rightpair.second);
        return {withroot, withoutroot};
    }
};