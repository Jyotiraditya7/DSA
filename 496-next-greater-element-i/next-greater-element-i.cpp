class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        vector<int>ans(nums1.size(),-1);
        for(int i =0;i<nums2.size();i++){
            int cur_el = nums2[i];
            while(!st.empty() && cur_el>st.top()){
                mp[st.top()]=cur_el;
                st.pop();
            }
            st.push(cur_el);
        }
        for(int i =0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                ans[i] = mp[nums1[i]];
            }
        }
        return ans;
    }
};