/*
1) iterate thorugh nums2 and apply the following logic:
if stack is empty then push nums2's el and its greater is nothing(or = -1)
if stack is not empty and nums2 el > stack's top el ,pop the stack till nums el encounters
an element in stack which is greater 
if stack top is greater then push nums2 el in stack
consider this: we are traversing from left to right, so when nums el > top and we pop, the 
nums2 el appears on the right side of popped el in array and hence it is just greater
element of top. so in map go to the key(=top element) and makes its value(greater element) as nums2 el

2) create an ans vector with nums1 size, since we only have to return those many elements 
which are just greater than each nums els.
3) run loop on nums1 and check if nums1 el exists in map, store its value in ans.(this will
only happen when in map its value(greater element) is updated via the while loop) otherwise
if an els does not exist in map then mp.find() = end and ans does not update its value(=defualt -1)
*/

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