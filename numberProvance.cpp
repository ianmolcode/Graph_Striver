class Solution
{
public:
    void dfs(int st, vector<int> adjls[], vector<int> &v)
    {
        v[st] = 1;
        for (auto it : adjls[st])
        {
            if (!v[it])
            {
                v[it] = 1;
                dfs(it, adjls, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<int> adjls[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<int> v(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (v[i] == 0)
            {
                cnt++;
                int st = i;
                dfs(st, adjls, v);
            }
        }
        return cnt;
    }
};