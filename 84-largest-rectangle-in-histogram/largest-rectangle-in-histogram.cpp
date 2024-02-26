/*class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int leftarr[n];
        int rightarr[n];
        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                leftarr[i]=0;
            }
            else{
                leftarr[i]=st.top()+1;
            }
                st.push(i);
        }
        for(int i =n-1;i>0;i--){
            while(!st.empty() && heights[i]<heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                rightarr[i]=n-1;
            }
            else{
                rightarr[i]=st.top()-1;
            }
            st.push(i);
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            ans = max(ans, heights[i]*(rightarr[i] - leftarr[i] +1));
        }
        return ans;

    }
};*/
class Solution {
  public:
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }
};