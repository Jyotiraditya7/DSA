/*2 approaches:
1st:-
1)we will go column wise and inside it row wise checking each spot if it is_possible()
2)is_possible(): nothing in left row,left upp diag,left low diag
3)for left row: row--,lud: row--,col--,lld:row++,col--
4)if is_possible()=true assign q to the string in array and call fn() with col+1 since each col has only 1 queen and we have assigned it already
5) backtrack

2nd:-
1) same logic but is_possible() will only change.instead of checking lr,lud,lld each time i.e to avoid O(3n) use this approach
2) for left row: maintain visited array
for lld: array(2n-1 size)(since last element in array will be 3+3=6=8-1 size) once q assigned,update row+col=index in lld array,so next time we have to check, we will just check if curr row+col=index is marked or not in lld array see img: 51(1)
for lud:  array(2n-1 size) once q assigned,update (n-1)+(col-row)=index in lud array,so next time we have to check, we will just check if (n-1)+(col-row)= index is marked or not in lud array see img: 51(2) */
class Solution {
public:
    void fn(int col,int n,vector<vector<string>>&ans,vector<string>&board,vector<int>&leftrow,vector<int>&uppdiag,vector<int>&lowdiag){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++){
            if(leftrow[row]==0 && lowdiag[row+col]==0 && uppdiag[n-1+col-row]==0){  
            //imp uppdiag-> n-1+col-row
            // make uppdiag and lowdiag vector of size 2*n-1 = 16-1= 15 = 0th index to 14th index<- 7+7
                board[row][col]='Q';
                leftrow[row]=1;
                lowdiag[row+col]=1;
                uppdiag[n-1+col-row]=1;

                fn(col+1,n,ans,board,leftrow,uppdiag,lowdiag);
                board[row][col]='.';
                leftrow[row]=0;
                lowdiag[row+col]=0;
                uppdiag[n-1+col-row]=0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0);
        vector<int>uppdiag(2*n-1,0);
        vector<int>lowdiag(2*n-1,0);
        fn(0,n,ans,board,leftrow,uppdiag,lowdiag);  
        return ans;      
    }
};