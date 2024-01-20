/* 
1)min heap bana ke topmost(min) element delete kiya
2)heap is of k size, so if 1st largest so only 1 element(largest) will be in heap,each time smaller being rejected
3) at end just return top
*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>>min_heap;
        for(int i =0;i<nums.size();i++){
            min_heap.push(nums[i]);
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};