/*1) define queue,ans variable and push root with index 0 in q.
2) start with root node and and then pop and then acc to index push left and right nodes.
3) now in the queue,the nodes present are of particular same level like level 1
4) note the size of queue currently which is also = no. of nodes in current level
5) iterate through the queue elements for i = 0 to i<size i.e iterate through all the nodes in ucrrent level.
6)before starting iteration note index of leftmost element in current level,-> front of queue.
7) now when you iterate over each element in current level ie till <size of queue, pop the element,
see if its first element or last element if yes then update first and last index for calculation of width,
if not then insert its left and right child based on currIndex = the index of element-minindex(which we have recorded before iteration ->eftmost)
left child index = 2*curr_index+1 and right child index = 2*curr_index+2
8) after iteration of each level caculate width fo current level as (last-first+1) and compare if it's greater than previous widths
9) return ans
*/




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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*, int>>q;
        if(root == NULL)
            return ans;
        q.push({root,0});
        while(!q.empty()){
            int min_index = q.front().second;
            int level_size = q.size();
            int first,last=0;
            for(int i =0;i<level_size;i++){
                int curr_index = q.front().second-min_index;
                if(i==0)
                    first = curr_index;
                else if(i==level_size-1)
                    last = curr_index;
                TreeNode* curr_node = q.front().first;
                q.pop();
                if(curr_node->left !=NULL){
                    q.push({curr_node->left,(long long)2*curr_index+1});// long long because value is actually becoming more than twice and if its a big int then overflow occurs
                }
                if(curr_node->right !=NULL){
                    q.push({curr_node->right,(long long)2*curr_index+2});
                }
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }
};