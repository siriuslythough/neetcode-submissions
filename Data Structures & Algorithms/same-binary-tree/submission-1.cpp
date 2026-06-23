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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr) return p==q; //if any is empty, return true is both empty, else false
        bool ans_root = p->val==q->val;
        bool ans_left = isSameTree(p->left, q->left);
        bool ans_right = isSameTree(p->right, q->right);
        return ans_root && ans_left && ans_right; 
    }
};
