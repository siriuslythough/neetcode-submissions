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
        // the first node is the one that is at start of IN and the middle of PRE
        // you then check the half section of IN and PRE with the first node omitted, 
        // then repeat this recursion.
        // so you need a helper function to which you can pass the start index and end index for checking
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
