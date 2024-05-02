class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        vector<bool> hashh(2001,0);
        int ans=-1;
        for(int &it:nums)
        {
            hashh[it+1000]=true;
            if(hashh[it+1000]&&hashh[1000-it])
                ans=max(ans, abs(it));
        }
        return ans;
    }
};