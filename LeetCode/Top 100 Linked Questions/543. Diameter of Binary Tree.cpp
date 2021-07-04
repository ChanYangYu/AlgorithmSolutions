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
    int res;
    int solve(TreeNode* root){
        int left = 0;
        int right = 0;
        if(root->left != NULL)
            left = solve(root->left) + 1;
        if(root->right != NULL)
            right = solve(root->right) + 1;
        
        res = max(res, left + right);
        
        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_depth = solve(root);
        
        return max(max_depth, res);
    }
};
