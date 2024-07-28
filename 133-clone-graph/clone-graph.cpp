/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
/*steps:
create one node = og node starting,update visited array
for every neighbour in og node starting
1) create new node
2) push this node as previously created newnode ka neigbour
3) update visited array with this new node 
4) recursion/dfs and pass this node, along with this node ka og node, and visited array into dfs function
*/
void dfs(Node* newnode,Node* curr_node,vector<Node*>&visited){
    visited[curr_node->val]=newnode;
    for(auto el: curr_node->neighbors){
        if(visited[el->val]==NULL){
            Node* temp = new Node(el->val);
            (newnode->neighbors).push_back(temp);
            dfs(temp,el,visited);
        }
        else{
            (newnode->neighbors).push_back(visited[el->val]); // since we can't insert el as it is original node
        }
    }
}
public:
    Node* cloneGraph(Node* node) { 
        if(node==NULL){
            return NULL;
        }
        Node* copy = new Node(node->val);
        vector<Node*>visited(101,NULL);
        dfs(copy,node,visited);
        return copy;
        


    }
};