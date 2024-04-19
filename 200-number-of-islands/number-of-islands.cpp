class Solution
{
private:
    void removeIsland(int i, int j, vector<vector<bool>> &tmp)
    {
        int r=tmp.size();
        int c=tmp[0].size();

        if(i<0||i==r||j<0||j==c||tmp[i][j]==0)
            return ;
        
        tmp[i][j]=0;

        removeIsland(i, j+1, tmp); //connected islands go brrrrrr
        removeIsland(i, j-1, tmp);
        removeIsland(i+1, j, tmp);
        removeIsland(i-1, j, tmp);
    }
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;

        vector<vector<bool>> tmp(r,vector<bool>(c,0)); //copy of grid we can delete islands from tmp

        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(grid[i][j]=='1')
                    tmp[i][j]=1;

        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(tmp[i][j]==1)
                {
                    ans+=1;
                    removeIsland(i,j,tmp);
                }
        return ans;
    }
};