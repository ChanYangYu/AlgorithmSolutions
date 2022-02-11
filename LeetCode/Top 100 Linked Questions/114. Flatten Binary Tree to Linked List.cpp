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
    vector<int> number;
    
    TreeNode* preorder(TreeNode * root) {
        if(root == NULL)
            return NULL;
        
        TreeNode* new_left = root->left;
        TreeNode* new_right = root->right;
        
        if(root->left != NULL)
            new_left = preorder(root->left);
        if(root->right != NULL)
            new_right = preorder(root->right);
        
        // preorder된 new_left right에 이어붙임
        root->left = NULL;
        root->right = new_left;
        
        // 이어붙여진 new_left가 NULL인 경우
        if(root->right == NULL){
            // new_right를 right에 이어붙임
            root->right = new_right;
        }
        else{
            // new_left 맨 끝 노드의 right에 new_right를 이어붙임
            TreeNode* cur = root;
            
            while(cur->right != NULL)
                cur = cur->right;
            
            cur->right = new_right;
        }
        
        return root;
        
    }
    void flatten(TreeNode* root) {
        preorder(root);
    }
};
