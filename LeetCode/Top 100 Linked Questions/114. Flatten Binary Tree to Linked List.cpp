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
        
        // preorder�� new_left right�� �̾����
        root->left = NULL;
        root->right = new_left;
        
        // �̾�ٿ��� new_left�� NULL�� ���
        if(root->right == NULL){
            // new_right�� right�� �̾����
            root->right = new_right;
        }
        else{
            // new_left �� �� ����� right�� new_right�� �̾����
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
