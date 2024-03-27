class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int ans=0;
        int lo=0,tmp=1;
        for(int hi=0;hi<nums.size();++hi)
        {
            tmp*=nums[hi];
            while(lo<=hi && tmp>=k)
            {
                tmp/=nums[lo];
                ++lo;
            }
            ans+=(hi-lo+1);
        }
        return ans;
    }
};