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
        int ans =INT_MIN;
        maxpath(root,ans);
        return ans;
    }
    int maxpath(TreeNode* node,int &ans){
        if(node==NULL)
            return 0;
        int leftsum = max(0,maxpath(node->left,ans)); // if leftsum or rightsum is 0 then we'll not consider it
        int rightsum = max(0,maxpath(node->right,ans));
        ans = max(ans,node->val+leftsum+rightsum);
        return node->val+max(leftsum,rightsum);
    }
};