class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len=0;
        string ans;
        vector<vector<int>>dp(n,vector(n,0));
        for(int diff=0;diff<n;diff++){
            for(int i =0,j=i+diff;j<n;i++,j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(diff==1){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]!=0){
                        dp[i][j]=dp[i+1][j-1]+2;
                    }
                }
                if(dp[i][j]!=0){
                    if(j-i+1>max_len){
                        max_len=j-i+1;
                        ans = s.substr(i,max_len);
                    }
                }
            }
        }
        return ans;
    }
};