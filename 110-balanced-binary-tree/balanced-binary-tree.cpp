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
 //balanced binary tree: for every node abs(lh-rh)<=1//
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return bal(root)!=-1;
    }
    int bal(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int lh = bal(node->left);
        int rh = bal(node->right);
        if(lh==-1 || rh ==-1)  // if(lh || rh ==-1) this is not correct checking statement bcz it will evaluate to
            return -1; //           (lh||rh) is this == true(anything apart from 0 is true and 0 is false so here -1 means true)
        if(abs(lh-rh)>1) //         so true||anything = true and true ==-1 yes then it return -1 which is not correct
            return -1;
        return(1+max(lh,rh));
    }
};