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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // you checked from the given vectors that:
        // the first ROOT is the one that is at start of PRE
        // you find that ROOT in the IN and the elements to the left and right are immediate subtrees
        // you keep going ahead in the PRE and you will get newer nodes
        // until all elements have been covered in IN then that last section of PRE is rightmost subtree

        // PRE gives root information 
        // IN gives left and right subtree information


        // So IN is NECESSARY to construct a unique binary tree because it gives you the Structural Info
        // through left and right subtree informations

        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto mid = find(inorder.begin(), inorder.end(), preorder[0])-inorder.begin();
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
        root->left = buildTree(leftPre, leftIn);   
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
