class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c)
    {
        double ans=0;
        int tmp=0,a=0;
        for(auto &it:c)
        {
            int arrival=it[0];
            int cooking=it[1];
            tmp=max(tmp,arrival)+cooking;
            ans+=tmp-arrival;
            ++a;
        }
        return ans/a;
    }
};