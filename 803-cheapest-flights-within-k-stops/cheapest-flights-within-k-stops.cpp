const int MY_INFINITY=1e5;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int> ans(n,MY_INFINITY);
        ans[src]=0;
        for(int i=0;i<=k;++i)
        {
            vector<int> tmp(ans);
            for(auto e:flights)
                tmp[e[1]]=min(tmp[e[1]],ans[e[0]]+e[2]);
            ans=tmp;
        }
        return ans[dst]==MY_INFINITY?-1:ans[dst];
    }
};