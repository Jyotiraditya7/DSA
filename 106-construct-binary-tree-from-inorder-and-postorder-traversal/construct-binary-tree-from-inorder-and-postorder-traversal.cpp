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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* ans = build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
        return ans;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd,map<int,int>&mp){
        if(inStart>inEnd || postStart>postEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inroot = mp[root->val];
        int num_of_left = inroot-inStart;

        root->left = build(inorder,postorder,inStart,inroot-1,postStart,postStart+num_of_left-1,mp);
        root->right = build(inorder,postorder,inroot+1,inEnd,postStart+num_of_left,postEnd-1,mp);
        return root;
    }
};