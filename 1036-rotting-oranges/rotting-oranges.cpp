class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[m][n];
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int tm =0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i =0;i<4;i++){
                int dx = r+drow[i];
                int dy = c+dcol[i];
                if(dx>=0 && dx<m && dy>=0 && dy<n && vis[dx][dy]!=2 && grid[dx][dy]==1){
                    q.push({{dx,dy},tm+1});
                    vis[dx][dy]=2;
                }
            }
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)
                    return -1;
            }
        }
        return tm;
    }
};