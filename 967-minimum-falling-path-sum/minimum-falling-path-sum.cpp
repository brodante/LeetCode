class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m)
    {
        int n=m.size();
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int mid=m[i-1][j];
                int left=j>0?m[i-1][j-1]:INT_MAX;
                int right=j<(n-1)?m[i-1][j+1]:INT_MAX;
                m[i][j]+= min(min(mid,left),right);
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;++j)
            ans=min(ans,m[n-1][j]);
        return ans;
    }
};