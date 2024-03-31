class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        int n=nums.size();
        long long ans=0, j1,j2,j3;
        j1=j2=j3=-1;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<minK || nums[i]>maxK)
                j3=i;
            if(nums[i]==minK)
                j1=i;
            if(nums[i]==maxK)
                j2=i;
            ans+=max(0LL,min(j1,j2)-j3);
        }
        return ans;
    }
};