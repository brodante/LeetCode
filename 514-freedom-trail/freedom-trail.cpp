class Solution {
private:
    vector<vector<int>> dp;
    int dfs(string &ring, string &key, int ptr, int index)
    {
        int n=ring.size();
        int m=key.size();
        if(index>=m)
            return 0;
        
        if(dp[index][ptr]!=-1)
            return dp[index][ptr];

        int ans=INT_MAX;

        for(int i=0;i<n;++i)
        {
            if(ring[i]==key[index])
                ans=min(ans,min(abs(i-ptr),n-abs(i-ptr))+1+dfs(ring,key,i,index+1));
        }
        dp[index][ptr]=ans;
        return ans;
    }
public:
    int findRotateSteps(string ring, string key)
    {
        int ptr=0;
        int index=0;
        int n=ring.size();
        int m=key.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return dfs(ring, key, ptr, index);        
    }
};