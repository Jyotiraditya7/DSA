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
    bool isSymmetric(TreeNode* root) {
        return(fn(root->left,root->right));
    }
    bool fn(TreeNode* left_root,TreeNode* right_root){
        if(left_root == NULL || right_root==NULL)
            return (left_root==right_root);
        return((left_root->val == right_root->val) && fn(left_root->left,right_root->right) && fn(left_root->right,right_root->left));

    }

};