class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int ans=0;
        int tmp=0;
        unordered_map<int,int> mpp;
        for(int it:nums)
        {
            mpp[tmp]++;
            tmp+=it;
            ans+=mpp[tmp-goal];
        }
        return ans;
    }
};