class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        vector<int> hashh(2001,0);
        int ans=-1;
        for(int &it:nums)
        {
            if(hashh[-it+1000])
                ans=max(ans, abs(it));
            ++hashh[it+1000];
        }
        return ans;
    }
};