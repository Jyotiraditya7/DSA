class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        /*if(n ==1 && m==1 && haystack[0]==needle[0]){
            return 0;
        }*/
        for(int i =0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};