class Solution {
private:
    vector<unordered_set<int>> adj;
    vector<int> subtreecount, ans;
    int N;
    void dfsBase(int root, int pre)
    {
        for(int it:adj[root])
        {
            if(it==pre)
                continue;
            dfsBase(it, root);
            subtreecount[root]+=subtreecount[it];
            ans[root]+=ans[it]+subtreecount[it];
        }
    }

    void dfs(int root, int pre)
    {
        for(int it:adj[root])
        {
            if(it==pre)
                continue;
            ans[it]=ans[root]-subtreecount[it]+N-subtreecount[it];
            dfs(it, root);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        adj.resize(n);
        ans.assign(n,0);
        subtreecount.assign(n,1); // all nodes are at 1 depth from themselves
        for(vector<int> &it:edges)
        {
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        N=n;
        dfsBase(0, -1);
        dfs(0, -1);
        return ans;
    }
};