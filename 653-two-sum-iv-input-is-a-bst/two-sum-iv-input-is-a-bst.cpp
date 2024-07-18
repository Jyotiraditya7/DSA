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
class BSTIterator{
    stack<TreeNode*> mystack;
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool input_isreverse){
        reverse = input_isreverse;
        pushall(root);
    }

    bool hasNext(){
        return !mystack.empty(); //hasnext if stack is not empty so true
    }
    int next(){
        TreeNode* temp = mystack.top();
        mystack.pop();
        if(!reverse) pushall(temp->right);
        else{
            pushall(temp->left);
        }
        return temp->val;
    }
private:
    void pushall(TreeNode* node){
        while(node!=NULL){
            mystack.push(node);
            if(reverse==true){ // reverse is true -> backwards or descending -> large value printed first->large value inserted at the top of stack
                node = node->right;
            }
            else{ // reverse if false -> forwards -> small value printed first ->small value inserted at the top of stack
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator n(root,false);
        BSTIterator b(root,true);
        int i = n.next();
        int j = b.next();
        while(i<j){ // note i and j are directly nodes->val but in 2 sum problem they are indexes
            if(i+j==k){
                return true;
            }
            else if(i+j<k){
                i = n.next();
            }
            else{
                j = b.next();
            }
        }
        return false;
    }
};