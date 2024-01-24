class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n=nums.size();
        int actual_sum=accumulate(nums.begin(),nums.end(),0);
        unordered_set<int> s(nums.begin(),nums.end());
        int unique_sum=accumulate(s.begin(),s.end(),0);
        int expected_sum = n*(n + 1)/2;
        int duplicate=actual_sum-unique_sum;
        int missing=expected_sum-unique_sum;
        return {duplicate, missing};
    }
};