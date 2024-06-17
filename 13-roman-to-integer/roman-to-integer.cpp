class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int value=0;
        for(int i =0;i<n-1;i++){
            if(mp[s[i]]<mp[s[i+1]]){ //eg IV so s[i] should be >= s[i+1] but if its not then do this
                value -= mp[s[i]];
            }
            else{
                value += mp[s[i]];
            }
        }
        value+=mp[s[n-1]];
        return value;
    }
};