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
    int maxDepth(TreeNode* root) {
        int ret = 1;
        if(root == NULL)
            return 0;
        if(root->left != NULL)
            ret = max(maxDepth(root->left) + 1, ret);
        if(root->right != NULL)
            ret = max(maxDepth(root->right) + 1, ret);
        
        return ret;
    }
};
