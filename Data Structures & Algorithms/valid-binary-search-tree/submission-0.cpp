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
    bool isValidBST(TreeNode* root) {
        // GREAT QUESTION FOR BINARY SEARCH TREE 

        // You missed the part that said:
        // The whole subtree has to follow the rule on the larger than or smaller than thing
        // So you need to check if the right child is still less than ancestors on left branch or not
        // while it is greater than its parent 
        // THAT'S WHY YOU WERE INTRODUCED THE TRACKING OF MIN AND MAX RANGE!

        // DFS -> use preorder traversal -> check node, then check children -> go down
        return valid(root, INT_MIN, INT_MAX);
        
    }
private:
    bool valid(TreeNode* node, int lb, int ub){
        if (!node) return true; // usual base case, 
        if (node->val>=ub || node->val<=lb) return false; // the condition that breaks BST
        return valid(node->left, lb, node->val) && valid(node->right, node->val, ub);
    }
};
