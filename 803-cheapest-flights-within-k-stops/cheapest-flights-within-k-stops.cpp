class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> ans(n,INT_MAX);
        ans[src]=0;
        for(int i=0;i<=k;++i)
        {
            vector<int> tmp(ans);
            for(auto e:flights)
                if(ans[e[0]]!=INT_MAX)
                    tmp[e[1]]=min(tmp[e[1]],ans[e[0]]+e[2]);
            ans=tmp;
        }
        return ans[dst]==INT_MAX?-1:ans[dst];
    }
};