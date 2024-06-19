class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();
        sort(strs.begin(),strs.end()); // this will sort lexicographically and we only need
        for(int i =0;i<min(strs[0].size(),strs[n-1].size());i++){ // to compare first and last word
            if(strs[0][i]!=strs[n-1][i]){
                return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};