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
    /*TreeNode* bstFromPreorder(vector<int>& preorder) {
        return(fn(preorder,0,preorder.size()-1));
    }
    TreeNode* fn(vector<int>& preorder,int preStart,int preEnd){
        if(preStart>preEnd) // think why not >= because if preStart>=Preend then for this example 5->left will be none try doing the dry run
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int i;
        for(i = preStart;i<preorder.size();i++){
            if(preorder[i]<=preorder[preStart]) continue;
            else break;
        }
        root->left = fn(preorder,preStart+1, i-1);
        root->right = fn(preorder,i,preEnd);
        return root;
    }*/
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i =0;
        return(build(preorder,i,INT_MAX));
    }
    TreeNode* build(vector<int>& preorder,int &i,int ub){
        if(i==preorder.size() || preorder[i] > ub)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root->left = build(preorder,i,root->val);
        root->right = build(preorder,i,ub);
        return root;

    }
    
};