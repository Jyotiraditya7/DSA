class Solution {
public:
    void dfs_fn(vector<vector<int>>& ans,vector<vector<int>>& image, int row, int col, 
    int new_color,int iniColour,int nrows,int ncols,int delrow[],int delcol[]){
        ans[row][col] = new_color;
        for(int i =0;i<4;i++){
            int diff_row = row+delrow[i];
            int diff_col = col+delcol[i];
            if(diff_row >=0 && diff_row <nrows && diff_col >=0 && diff_col <ncols && 
            image[diff_row][diff_col]==iniColour && ans[diff_row][diff_col]!=new_color){
                dfs_fn(ans,image,diff_row,diff_col,new_color,iniColour,nrows,ncols,delrow,delcol);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int iniColour = image[sr][sc];
        int nrows = image.size();
        int ncols = image[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        dfs_fn(ans,image,sr,sc,color,iniColour,nrows,ncols,delrow,delcol);
        return ans;
    }
};