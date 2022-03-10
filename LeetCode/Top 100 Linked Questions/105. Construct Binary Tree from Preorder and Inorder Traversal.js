/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
let p, i;
let mp;

const makeTree = (preorder, inorder) => {
    if(preorder.length === p || inorder.length === i)
        return null;
    if(mp[inorder[i]])
        return null;
    const newNode = new TreeNode(preorder[p]);
    
    mp[preorder[p]] = true;
    if(preorder[p] !== inorder[i]){
        p++;
        newNode.left = makeTree(preorder, inorder);
    }
    else{
        p++;
        i++;
        newNode.right = makeTree(preorder, inorder);
    }
    
    if(newNode.val === inorder[i]){
        i++;
        newNode.right = makeTree(preorder, inorder);
    }
    
    return newNode;
}
var buildTree = function(preorder, inorder) {
    p = 0;
    i = 0;
    mp = {};
    return makeTree(preorder, inorder);
};