class Solution
{
public:
    void Dfs(vector<vector<int>> &image, vector<vector<int>> &imagecopy, int row, int col, int newcolor, int delrow[], int delcol[], int initialcolor)

    {
        int n = image.size();
        int m = image[0].size();

        imagecopy[row][col] = newcolor;
        for (int i = 0; i < 4; i++)
        {

            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && imagecopy[newrow][newcol] == initialcolor && imagecopy[newrow][newcol] != newcolor)
            {
                Dfs(image, imagecopy, newrow, newcol, newcolor, delrow, delcol, initialcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> imagecopy = image;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int initalcolor = image[sr][sc];
        Dfs(image, imagecopy, sr, sc, color, delrow, delcol, initalcolor);
        return imagecopy;
    }
};