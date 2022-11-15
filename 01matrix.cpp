class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int  m = mat[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0)) ; //visited array 
        vector<vector<int>>dis(n, vector<int>(m,0)) ; //distance array
        queue<pair<pair<int,int> , int>>q ;
           
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                  {
                    q.push({{i, j}, 0});
                    vis[i][j]=1 ; 
                }
                
                else{ 
                    vis[i][j]=0 ; 
                }
                
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
          while (!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int data= q.front().second ; 
            
            q.pop();
             
            dis[row][col]=data ; 
              
             for (int i = 0; i < 4; i++)
            {
                int newRow = delRow[i] + row;
                int newCol = delCol[i] + col;

                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && vis[newRow][newCol]==0)
                {  
                    vis[newRow][newCol]=1 ; 
                    q.push({{newRow, newCol}, data + 1});
                   
                }
            }  
          } 
        return dis ; 
        
 
    }
};