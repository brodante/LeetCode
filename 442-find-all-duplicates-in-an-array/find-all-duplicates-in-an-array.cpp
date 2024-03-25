class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ans;
        for(int &num:nums)
        {
            int index=abs(num)-1;
            if(nums[index]<0)
                ans.emplace_back(index+1);
            nums[index]*=-1;
        }
        return ans;
    }
};