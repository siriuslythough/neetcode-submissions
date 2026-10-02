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
        unordered_map<int,int> inmap;
        for(int i = 0; i<inorder.size(); i++){
            inmap[inorder[i]] = i;
        }
        int preidx = 0;
        return build(preorder, preidx, 0, inorder.size()-1, inmap);
    }
private:
    TreeNode* build(vector<int>& preorder, int& preidx, int instart, int inend, const unordered_map<int, int>& inmap){
        // invalid inorder range
        if(instart>inend) return nullptr;
        // current root value comes from the current preorder index
        int rootval = preorder[preidx];
        preidx++;
        TreeNode* root = new TreeNode(rootval);

        // O(1) lookup for root position in the inorder sequence
        int mid = inmap.at(rootval);

        // build left subtree, then the right subtree
        root->left = build(preorder, preidx, instart, mid-1, inmap);
        root->right = build(preorder, preidx, mid+1, inend, inmap);\
        return root;
    }
};
