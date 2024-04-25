class Solution {
public:
    int longestIdealString(string s, int k)
    {
        int ans=0;
        vector<int> dp(26,0);
        for(int i=0;i<s.size();++i)
        {
            int tmp=s[i]-'a';
            for(int j=tmp;j>=0 && j>=tmp-k;--j)
                dp[tmp]=max(dp[tmp],dp[j]+1);
            for(int j=tmp+1;j<26 && j<=tmp+k;++j)
                dp[tmp]=max(dp[tmp],dp[j]+1);
            ans=max(ans,dp[tmp]);
        } 
        return ans;
    }
};