class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s)
    {
        map<int, float, greater<int>> mpp;
        for(int i=0;i<p.size();++i)
            mpp[p[i]]=(float)(t-p[i])/s[i];
        int ans=0;
        float cur=0;
        for(pair<int, float> it:mpp)
            if(it.second>cur)
            {
                cur=it.second;
                ++ans;
            }
        return ans;
    }
};