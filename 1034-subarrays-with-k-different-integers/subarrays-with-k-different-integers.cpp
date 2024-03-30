class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        unordered_map<int,int> mpp;
        int lnear,lfar,ans;
        lnear=lfar=ans=0;
        
        for(int hi=0;hi<nums.size();++hi)
        {
            ++mpp[nums[hi]];

            while(mpp.size()>k)
            {
                --mpp[nums[lnear]];
                if(mpp[nums[lnear]]==0)
                    mpp.erase(nums[lnear]);
                ++lnear;
                lfar=lnear;
            }

            while(mpp[nums[lnear]]>1)
            {
                --mpp[nums[lnear]];
                ++lnear;
            }
            if(mpp.size()==k)
                ans+=lnear-lfar+1;
        }

        return ans;
    }
};