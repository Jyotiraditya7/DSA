/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        if(lists.size()==0) return NULL;

        for(int i =0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push({lists[i]->val,lists[i]});
            }
        }

        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(it.second->next !=NULL){
                pq.push({it.second->next->val,it.second->next});
            }
            temp->next = it.second;
            temp = temp->next;
        }
        return dummynode->next;
    }
};
/*
1) push 1st element of each linked list into a priority queue(min heap) along with its value( i.e pair<value,the node>) as min heap will sort accroding to value
2) create dummynode and pointer temp
3)remove the topmost element of min heap and insert into the next of dummynode
4) before inserting to dummy node linkedlist, check if the el's next is not null and insert its next+next's value into the heap
5) repeat step 3 to 4 till min heap is not empty.also while removing from heap and inserting from individual linked list,at the end all linked list pointer will reach the end(=NULL).
*/