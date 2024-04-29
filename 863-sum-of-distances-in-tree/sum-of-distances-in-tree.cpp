class Solution {
private:
    long base_result=0;
    vector<int> subtreecount;
    int N;
    int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth)
    {
        int total_count=1;
        base_result+=curr_depth;
        
        for(int &it:adj[curr_node])
        {
            if(it==prev_node)
                continue;
            total_count+=dfsBase(adj, it, curr_node, curr_depth+1);
        }
        subtreecount[curr_node]=total_count;

        return total_count;
    }
    void dfs(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int> &ans)
    {
        for(int &it:adj[parent_node])
        {
            if(it==prev_node)
                continue;
            ans[it]=ans[parent_node]-subtreecount[it]+(N-subtreecount[it]);
            dfs(adj, it, parent_node,ans);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> adj;
        N=n;
        subtreecount.assign(n,0);
        for(vector<int> &it:edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        base_result=0;

        dfsBase(adj, 0,-1, 0);

        vector<int> ans(n,0);
        ans[0]=base_result;

        dfs(adj, 0, -1, ans);
        return ans;
    }
};