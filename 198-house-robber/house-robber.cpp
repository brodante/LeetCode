class Solution {
public:
    int rob(vector<int>& nums)
    {
        long ans=0,ans2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
                ans=max(ans+nums[i],ans2);
            else
                ans2=max(ans2+nums[i],ans);
        }
    return ans>ans2?ans:ans2;
    }
};