class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        unordered_map<int,int> mpp;
        int ans=0,n=nums.size(),i=0;
        for(int j=0;j<n;++j)
        {
            ++mpp[nums[j]];
            while(i<=j&&mpp[nums[j]]>k)
            {
                --mpp[nums[i]];
                ++i;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};