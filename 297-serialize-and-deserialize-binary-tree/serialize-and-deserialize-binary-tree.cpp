/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curnode = q.front();
            q.pop();
            if(curnode==NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(curnode->val)+',');
            }
            if(curnode!=NULL){
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curnode = q.front();
            q.pop();

            //left node
            getline(s,str,',');
            if(str=="#"){
                curnode->left =NULL;
            }
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                curnode->left = leftnode;
                q.push(leftnode);
            }

            //right node
            getline(s,str,',');
            if(str =="#"){
                curnode->right = NULL;
            }
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                curnode->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));