class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s ="";
        int count =0;
        while(s.size()<b.size()){
            s+=a;
            count++;
        }
        if(s.find(b)!=string::npos){
            return count;
        }
        s+=a;
        count++;
        if(s.find(b)!=string::npos){
            return count;
        }
        return -1;
    }
};
/*
int n = a.size();
int m = b.size();
string temp = a;
int count =1;
while(a.size()<b.size()){
    a+=tp;
    count++;
}
if(chk(a,b)){
    return count;
}
a+=tp;
count++;
if(chk(a,b)){
    return count;
}
return -1;
bool chk(string a,string b){
    int n = a.size();
    int m = b.size();
    for(int i =0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(a[i+j]!=b[j]){
                break;
            }
        }
        if(j==m){
            return true'
        }
    }
    return false;
}
*/