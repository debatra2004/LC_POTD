class Solution {
public:
    vector<vector<int>> direc={{-1,1},{1,1},{1,-1},{-1,-1}};
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxlen=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxlen=max(maxlen,1);
                    maxlen=max(maxlen,dfs(i,j,0,2,grid,false));
                    maxlen=max(maxlen,dfs(i,j,1,2,grid,false));
                    maxlen=max(maxlen,dfs(i,j,2,2,grid,false));
                    maxlen=max(maxlen,dfs(i,j,3,2,grid,false));
                }
            }
        }
        return maxlen;
    }
    int dfs(int r,int c,int dir,int next,vector<vector<int>>& grid,bool turn){
        int nr=r+direc[dir][0];
        int nc=c+direc[dir][1];
        int m=grid.size();
        int n=grid[0].size();
        if(nr<0||nr>=m||nc<0||nc>=n||grid[nr][nc]!=next) return 1;
        int strval=1+dfs(nr,nc,dir,(next==2)?0:2,grid,turn);
        int trnval=0;
        if(!turn){
            trnval=1+dfs(nr,nc,(dir+1)%4,(next==2)?0:2,grid,true);
        }
        return max(strval,trnval);
    }
};