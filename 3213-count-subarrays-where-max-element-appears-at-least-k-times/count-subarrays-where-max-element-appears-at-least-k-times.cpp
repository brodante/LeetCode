class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        long long tmp=*max_element(nums.begin(),nums.end()), ans=0;
        long long i=0,curr=0;
        for(int j=0;j<nums.size();++j)
        {
            if(nums[j]==tmp)
                ++curr;
            while(curr>=k)
                if(nums[i++]==tmp)
                    --curr;
            ans+=i;
        }
        return ans;
    }
};