class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        unordered_map<int,int> mpp;
        int ans=0,i=0,n=nums.size();
        for(int j=0;j<n;++j)
        {   
            ++mpp[nums[j]];
            while(mpp[nums[j]]>k)
                --mpp[nums[i++]];
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};