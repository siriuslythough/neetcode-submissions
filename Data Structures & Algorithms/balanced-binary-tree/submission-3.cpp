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
        maxh_oneshot(root, maxi);
        return maxi;
    }
private:
    int maxh_oneshot(TreeNode* root, int& maxi){
        if(root==nullptr) return 0;
        int lefth = maxh_oneshot(root->left, maxi);
        int righth = maxh_oneshot(root->right, maxi); //recursion golden rule, dont call it again and again
        //call once, store, remember, dont calculate again and again
        maxi = max(maxi,lefth+righth);
        return 1+max(lefth, righth);
    }
};
