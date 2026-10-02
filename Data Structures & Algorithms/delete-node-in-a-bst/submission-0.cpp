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
    TreeNode* deleteNode(TreeNode* root, int key) { 
        if(!root) return nullptr;
        if(key<root->val) root->left = deleteNode(root->left, key);
        else if (key>root->val) root->right = deleteNode(root->right, key);
        else{
            if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right); // if both children present, travel down right until find the empty right
            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val); // delete successor node from right subtree
        }
        return root;
        // main thing we learned here is how a tree can be changed and its status can be updated back up to the root
    }
private:
    TreeNode* findMin(TreeNode* node){
        while(node->left) node = node->left;
        return node;
    }
};