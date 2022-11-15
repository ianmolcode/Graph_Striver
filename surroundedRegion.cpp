class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delRow[], int delCol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < 4; i++)
        {

            int newrow = row + delRow[i];
            int newcol = col + delCol[i];
            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol] && mat[newrow][newcol] == 'O')
            {
                dfs(newrow, newcol, vis, mat, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // traversing the first and the last row
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int j = 0; j < m; j++)
        {
            // first row
            if (!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(0, j, vis, mat, delRow, delCol);
            }
            // last row

            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, vis, mat, delRow, delCol);
            }
        }
        // tarversing the first and the last col
        for (int i = 0; i < n; i++)
        {
            // first col
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, delRow, delCol);
            }
            // last col
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(i, 0, vis, mat, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 0)
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <bits/stdc++.h>
                                                                                                                                                                                                using namespace std;

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &mat, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();

        // check for top, right, bottom, left
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            // check for valid coordinates and unvisited Os
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m,
                              vector<vector<char>> mat)
    {
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // traverse first row and last row
        for (int j = 0; j < m; j++)
        {
            // check for unvisited Os in the boundary rows
            // first row
            if (!vis[0][j] && mat[0][j] == 'O')
            {
                dfs(0, j, vis, mat, delrow, delcol);
            }

            // last row
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
            {
                dfs(n - 1, j, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            // check for unvisited Os in the boundary columns
            // first column
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, delrow, delcol);
            }

            // last column
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
            {
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }

        // if unvisited O then convert to X
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

int main()
{

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    Solution ob;
    // n = 5, m = 4
    vector<vector<char>> ans = ob.fill(5, 4, mat);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}