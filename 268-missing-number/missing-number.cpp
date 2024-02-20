class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int x;
        int l=nums.size();
        x=(l*(l+1))/2;
        for(int i:nums)
            x-=i;
        return x;
    }
};