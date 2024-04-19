class Solution {
private:
    int bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& mpp)
    {
        deque<pair<int,int>> q;
        mpp[i][j]=true;
        q.push_front({i,j});
        while(!q.empty())
        {
            pair<int,int> rc=q.front();
            q.pop_front();
            int x = rc.first;
            int y = rc.second;
            vector<pair<int,int>> directions={{-1,0},{1,0},{0, 1},{0,-1}}; //left, right, up, down
            for(pair<int,int> &it:directions)
            {
                int nx= x+ it.first;
                int ny= y+ it.second;
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]=='1' && !mpp[nx][ny])
                {
                    mpp[nx][ny]=true;
                    q.push_back({nx, ny});
                }
            }
        }
        return 1;
    }
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<bool>> mpp(r,vector<bool>(c,0));

        int ans=0;

        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(grid[i][j]=='1'&&mpp[i][j]==false)
                {
                    bfs(i,j,grid,mpp);
                    ++ans;
                    //or ans +=bfs(i, j, grid, mpp);
                }
        return ans;
    }
};