class Solution {
    struct node{
        int no;
        int freq;
    };
    struct comp{
        bool operator()(node const &a,node const &b){
            return a.freq<b.freq;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<node,vector<node>,comp>heap;
        for(int el : nums){
            mp[el]++;
        }
        for(auto it:mp){
            heap.push(node(it.first,it.second));
        }
        while(k--){ // stops at k=0
            node temp = heap.top();
            heap.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};