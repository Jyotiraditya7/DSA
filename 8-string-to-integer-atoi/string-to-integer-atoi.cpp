class Solution{
    public:
        int myAtoi(string s){
            int n = s.size();
            int i =0;
            int ans =0;
            bool isnegative = false;
            int max_value = INT_MAX/10;
            if (n==0){
                return 0;
            }
            while(i<n && s[i]==' '){
                i++;
            }
           // if(i<n){
                if(s[i]=='-'){
                    isnegative = true;
                    i++;
                }
                else if(s[i]=='+'){
                    i++;
                }
           // }
            while(i<n && isDigits(s[i])){ // not isdigit() inbuilt function as we are checking if s[i] is in '0' to '9' and not 0 to 9
                int digit = s[i]-'0';
                if(ans>max_value || (ans == max_value && digit >7)){
                    return isnegative ? INT_MIN : INT_MAX;
                }
                    ans = (ans*10)+digit;
                    i++;
            }
            return isnegative ? -ans : ans;
        }
    private:
        bool isDigits(char c){
            return(c>='0' && c<='9');
        }
};