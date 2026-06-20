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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;
        if (same(root, subRoot)) return true;
        bool left = isSubtree(root->left, subRoot); 
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
private:
    bool same(TreeNode* p, TreeNode* q){
        if(p==nullptr || q==nullptr) return p==q;
        return (p->val==q->val) && same(p->left, q->left) && same(p->right, q->right);
    }
};
