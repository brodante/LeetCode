class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if(n==1)
            return {0};

        unordered_map<int,vector<int>> adj;
        vector<int> indegree(n);

        for(vector<int> &it:edges) //adjacency list
        {
            int u=it[0];
            int v=it[1];
            ++indegree[u];
            ++indegree[v];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }

        vector<int> ans;
        queue<int> q;

        for(int i=0;i<n;++i)
            if(indegree[i]==1)
                q.push(i); //pushing leaf nodes into queue for bfs
        while(n>2)
        {
            int size=q.size();
            n-=size;
            while(size--)
            {
                int u=q.front();
                q.pop();
                for(int &it:adj[u])
                {
                    --indegree[it];
                    if(indegree[it]==1)
                    {
                        q.push(it);
                    }
                }
            }
        }
        while(!q.empty())
            ans.emplace_back(q.front()),q.pop();
        return ans;
    }
};