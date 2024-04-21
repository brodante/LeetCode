class Solution {
private:
    bool dfs(unordered_map<int,vector<int>> &mpp,int &src, int &dst, vector<bool> &vis)
    {
        if(src==dst)
            return true;
        if(vis[src]==true)
            return false;
        vis[src]=true;
        for(int it:mpp[src])
        {
            if(dfs(mpp,it,dst,vis)==true)
                return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst)
    {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<edges.size();++i)
        {
            mpp[edges[i][0]].push_back(edges[i][1]);
            mpp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);
        return dfs(mpp,src,dst,vis);
    }
};