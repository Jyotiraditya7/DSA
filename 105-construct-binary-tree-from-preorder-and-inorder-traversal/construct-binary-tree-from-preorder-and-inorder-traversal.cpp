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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* ans = build(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1,mp);
        return ans;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int inStart,int inEnd,int preStart,int preEnd,map<int,int>&mp){
        if(inStart>inEnd || preStart>preEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inroot = mp[root->val];
        int num_of_left = inroot-inStart;

        root->left = build(preorder,inorder,inStart,inroot-1,preStart+1,preStart+num_of_left,mp);
        root->right = build(preorder,inorder,inroot+1,inEnd,preStart+num_of_left+1,preEnd,mp);
        return root;
    }
};