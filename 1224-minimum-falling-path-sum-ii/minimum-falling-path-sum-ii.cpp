class Solution {
private:
    int helper(int r, int c,vector<vector<int>> &tmp, vector<vector<int>>& grid)
    {
        int n=grid.size();
        if(r==n-1)
            return grid[r][c];
        if(tmp[r][c]!=0)
            return tmp[r][c];
        int ans=INT_MAX;

        for(int j=0;j<n;++j)
        {
            if(c!=j)
                ans=min(ans,grid[r][c]+helper(r+1,j,tmp,grid));
        }
        tmp[r][c]=ans;
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int ans=INT_MAX;
        vector<vector<int>> tmp(n,vector<int>(n));
        for(int j=0;j<n;++j)
            ans=min(ans,helper(0,j,tmp,grid));
        return ans;
    }
};