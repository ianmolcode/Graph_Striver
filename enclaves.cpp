

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        int vis[m][n] = {0};
        // traverse the boundary of the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || i = m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
    }
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    while (!empty)
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        // 4 directional traversing for more 1s
        for (int i = 0; i < 4; i++)
        {
            int newRow = delRow[i] + row;
            int newCol = delCol[i] + col;

            if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
            {
                q.push({newRow, newCol});
                visited[newRow][newCol] = 1;
            }
        }

        int count = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    };