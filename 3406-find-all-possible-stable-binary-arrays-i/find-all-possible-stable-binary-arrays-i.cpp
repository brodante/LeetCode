class Solution {
public:
    int numberOfStableArrays(int x, int y, int l)
    {
        const int MOD=1e9+7;
        vector<vector<vector<int>>> dp(y+1, vector<vector<int>>(x+1, vector<int>(2,0)));
        dp[0][0][0]= dp[0][0][1]= 1;
        for(int i=0;i<=y;++i)
        {
            for(int j=0;j<=x;++j)
            {
                for(int k=1;k<=l;++k)
                {
                    if(i-k>=0)
                        dp[i][j][1]= (dp[i][j][1]+ dp[i-k][j][0])% MOD;
                    if (j-k>=0)
                        dp[i][j][0]= (dp[i][j][0]+ dp[i][j-k][1])% MOD;
                }
            }
        }
        return (dp[y][x][0]+dp[y][x][1])% MOD;
        
    }
};