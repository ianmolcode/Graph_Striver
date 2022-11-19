class Solution
{
public:
    vector<int> toposort(int V, vector<int> adj)
    {
        int indegree[V] = {0};
        for (auto it : adj)
        {
            for (auto itr : it)
            {
                indegree[itr]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans; 
    }
};