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
        if (root == nullptr) return true;
        int left_subtree_height = height(root->left);
        int right_subtree_height = height(root->right);
        // NOTE you are able to check the heights upto that point only
        // only checking at highest level will give wrong answer
        // because inside a subtree there could be imbalance at heights
        // but at higher level only max height is returned
        // so such skewness inside the subtree is hidden
        if(left_subtree_height-right_subtree_height>1 || left_subtree_height-right_subtree_height<-1){
            return false;
        }
        //now go ahead, use recursion to check for the subtrees and return result back to the top
        bool leftcheck = isBalanced(root->left);
        bool rightcheck = isBalanced(root->right);
        if(!leftcheck||!rightcheck) return false;
        return true;
    }
private:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
