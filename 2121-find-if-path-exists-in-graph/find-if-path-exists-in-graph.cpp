class Solution {
private:
    bool bfs(unordered_map<int,vector<int>> &mpp, vector<bool> &vis, int &src, int &dst)
    {
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            if(tmp==dst)
                return true;
            for(int it:mpp[tmp])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst)
    {
        unordered_map<int,vector<int>> mpp; //adjacency list
        for(int i=0;i<edges.size();++i)
        {
            mpp[edges[i][0]].push_back(edges[i][1]);
            mpp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n,false);

        return bfs(mpp,vis,src,dst);
    }
};