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
    int maxPathSum(TreeNode* root) {
        int globalmax = INT_MIN;
        peak(root, globalmax);
        return globalmax;
    }
private:
    int peak(TreeNode* node, int& maxsumbelow){
        if(!node) return 0;
        int leftsum = max(0, peak(node->left, maxsumbelow)); // completely ignore if the below branch gave negative sum
        int rightsum = max(0, peak(node->right, maxsumbelow)); // completely ignore if the below branch gave negative sum
        int peaksum = node->val + leftsum + rightsum; // if negatives not coming in, take peaksum as up to down path sum,
                                                      // with peak at current node
        maxsumbelow = max(maxsumbelow, peaksum); // update global max is what is seem at peak for up-down path is the max so far
        return node->val + max(leftsum, rightsum); // this is what the node is supposed to hold,
                                                   // the value of maximum seen downwards till now
    }
};
