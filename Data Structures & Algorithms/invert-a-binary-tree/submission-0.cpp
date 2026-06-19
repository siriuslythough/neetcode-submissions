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
    TreeNode* invertTree(TreeNode* root) {
        // base case: when you checked what you were returned, it was null
        if(root==nullptr){
            return nullptr;
        }
        // use recursion to assign inverted subtrees to left and right pointer
        TreeNode* invertedleft = invertTree(root->left); //passes down the left branch
        TreeNode* invertedright = invertTree(root->right); //passed down the right branch
        // now swap the pointers to the subtrees at the root
        root->left = invertedright;
        root->right = invertedleft;
        //return the root of the inverted part handled by you
        return root;
    }
};
