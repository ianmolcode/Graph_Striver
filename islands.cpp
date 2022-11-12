class Solution {
 public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid)
    { 
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int drow=-1;drow<=1;drow++)
            {
                for(int dcol=-1;dcol<=1;dcol++)
                {
                    int nrow=row+drow;
                    int ncol=col+dcol;
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
                    && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};
