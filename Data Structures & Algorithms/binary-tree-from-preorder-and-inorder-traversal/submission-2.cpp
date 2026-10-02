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
        // what i remember is just one is not enough
        // you always need a pair of traversals to figure out both the structure and the values
        // inorder gives sorted values
        if(preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);

        // find the index in the inorder corresponding to root given by the preorder, you need to take the cases ahead of the root and uptil and continued from mid
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin(); 
        vector<int> subleftpre(preorder.begin()+1, preorder.begin() + mid + 1);
        vector<int> subrightpre(preorder.begin()+mid+1, preorder.end());

        // inorder already has the mid used so do not include that
        vector<int> subleftin(inorder.begin(), inorder.begin() + mid);
        vector<int> subrightin(inorder.begin()+mid+1, inorder.end());
        root->left = buildTree(subleftpre, subleftin);
        root->right = buildTree(subrightpre, subrightin);
        return root;
    }
};
