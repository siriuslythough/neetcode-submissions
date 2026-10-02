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
    int kthSmallest(TreeNode* root, int k) {
        // the idea of early stopping
        int cnt = 0; 
        int ans = INT_MIN;
        dfs_stopk(root, k, cnt, ans);
        return ans;
    }
private:
    void dfs_stopk(TreeNode* root, int k, int& cnt, int& ans){
        if(!root || cnt>=k) return; // this is what makes the early stopping happen, you just start to return immediately from every thing, no processing nothing
        dfs_stopk(root->left, k, cnt, ans);
        cnt++;
        if(cnt == k){
            ans = root->val; 
            return;
        }
        dfs_stopk(root->right, k, cnt, ans);
    }
};
