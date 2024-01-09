/* if n(total elements) is odd then median is (n+1/2)th element. eg n=5 then 3rd element or 2nd index is median.
if n(total elements) is even then median is ((n/2)th+(n/2+1)th)/2 th element. eg n=6 then half of (3rd + 4th) element is median

 imp: for n is even-> both half have same no. of elements
         for n is odd -> left half will have 1 more than right(eg n=7 so left = 4 and right = 3)
see pic 4
1) let n1 be smaller array
2) let low =0 and high = n1
3) the mid1 will be number of elements from arr1 in left half (mid1=x and index 0 to mid1-1 elements will be taken). so mid2 will be len_lefthalf - x and index = 0 to mid2-1 elements will be taken from arr2 in lefthalf
4) rest of el from arr1 and arr2 in right half
5) now l1->last element of arr1 in left half, l2->last element of arr1 in left half, r1-> first element of arr1 in right half, r1-> first element of arr2 in right half.
also assign l1,l2 = int_min and r1,r2 = int_max

6) terminating condition is l1<=r2 and l2<=r1
if l1> r2 then more elements have been taken from arr1, so decrease x-> high = mid-1;
if l2> r1 then more elements have been taken from arr2, so increase x-> low = mid+1;
7) now for teminating conditon, if n is odd then median will be in left half(since if n=5 so left half has 3 elts and right =2), so max(l1,l2) is median
if n is even then (max(l1,l2)+min(r1,r2))/2 is median
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = n1+n2;
        int low =0;
        int high = n1;
        int left_half = (n1+n2+1)/2;
        while(low<=high){
            int mid1 = (low+high)/2;
            int mid2 = left_half-mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1 < n1)r1 = nums1[mid1];
            if (mid2 < n2)r2 = nums2[mid2];
            if (mid1 - 1 >= 0){
                l1 = nums1[mid1-1];
            }
            if (mid2 - 1 >= 0){
                l2 = nums2[mid2-1];
            }
            if(l1<=r2 && l2 <= r1){
                if(n%2==1){
                    return max(l1,l2);
                }
                else{
                    return ((double)max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else{
                low = mid1+1;
            }
        }
        return 0;
    }
};