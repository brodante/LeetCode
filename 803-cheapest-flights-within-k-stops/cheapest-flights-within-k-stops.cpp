class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> ans(n,INT_MAX);
        ans[src]=0;
        for(int i=0;i<=k;++i)
        {
            vector<int> tmp(ans);
            for(auto it:flights)
                if(ans[it[0]]!=INT_MAX)
                    tmp[it[1]]=min(tmp[it[1]],ans[it[0]]+it[2]);
            ans=tmp;
        }
        return ans[dst]==INT_MAX?-1:ans[dst];
    }
};