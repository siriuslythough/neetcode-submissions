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
    int kthSmallest(TreeNode* root, int k) {
        // __________________________PROPERTY___________________________
        // WHEN YOU DO AN IN-ORDER DFS TRAVERSAL ON A BINARY SEARCH TREE
        // YOU PARSE THE TREE IN A MANNER THAT GIVES YOU THE NUMBERS
        // IN AN INCREASING SORTED ORDER.
        vector<int> arr;
        inorder_dfs(root, arr);
        return arr[k-1];
    }
private:
    void inorder_dfs(TreeNode* node, vector<int>& arr){
        if(!node) return;
        inorder_dfs(node->left, arr); //left
        arr.push_back(node->val); //node
        inorder_dfs(node->right, arr); //right
    }
};
