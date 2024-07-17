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
   /*void fn(TreeNode* root, int k,int &count,int &ans){
        if(root==NULL)
            return;
        fn(root->left,k,count,ans);
        count++;
        if(count==k){
            ans = root->val;
            return;
        }
        fn(root->right,k,count,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans;
        fn(root,k,count,ans);
        return ans;
    }*/
    // we can do morris traversal because recursion takes recursion stack space O(N) whereas morris is O(1) space
    
    void morris(TreeNode* root,int k, int &ans){
        TreeNode* cur=root;
        int count=0;
        while(cur!=NULL){
            if(cur->left ==NULL){
                count++; // in this case we usually insert into inorder array
                if(count==k){
                    ans= cur->val;

                }
                cur=cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right != NULL && prev->right !=cur){ // imp to note the && condition too
                    prev = prev->right;
                }
                if(prev->right ==NULL){
                    prev->right = cur;
                    cur=cur->left;
                }
                else{
                    prev->right = NULL;
                    count++; // at this step we usually insert cur into inorder vector
                    if(count==k){
                        ans = cur->val;
                    }
                    cur = cur->right; // as left processed, node processed after returning from left subtree, now process right
                }

            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        morris(root,k,ans);
        return ans;
    }
};
