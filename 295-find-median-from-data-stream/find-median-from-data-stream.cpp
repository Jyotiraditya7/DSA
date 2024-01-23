/*
1)Create 2 heaps : one max heap and the other min heap
2)only store in max heap if the curr element is lesser than root node of max heap(since
root of max heap is largest and its children are smaller), else store in min heap (left wise).
3) after adding each element always check the size of both heaps. there will be 2 cases: balanced and unbalanced. Let maxheap.size() =n and minheap.size() = m . Balanced when n=m or when either n-m =1 or n-m = -1(any one of the heap has 1 more element than the other).
Unbalanced when size difference is 2 i.e n-m =2 or n-m =-2;
4) If unbalanced , then do balancing. This can be done by, if maxheap is greater then transfer its root node to minheap. If min heap is greater than transfer its root node to maxheap.
priority queue will automatically heapify the transferred element when storing.
(How transfer happens internally: swap root with last element of curr heap. delete last element of curr heap(i.e og root element) and trasnfer to other heap. heapify the curr heap)
5) now if (n+m)%2 =0 >> even then return (maxheap.top + minheap.top)/2 = ans
else if it is odd then return topmost element of whichever heap is greater.
*/


class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() && minheap.empty()){
            maxheap.push(num);
        }
        else if(num<=maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        int n = maxheap.size();
        int m = minheap.size();
        if(n-m == 2 || m-n ==2){
            if(n>m){
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
            }
            else{
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
        
    }
    
    double findMedian() {
        int n = maxheap.size();
        int m = minheap.size();
        if((n+m)%2 ==0){
            return ((double)maxheap.top()+(double)minheap.top())/2.0;
        }
        if(n>m){
            return (double)maxheap.top();
        }
        return (double)minheap.top();

        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */