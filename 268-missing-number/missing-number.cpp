class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int a=1;
        for(int i:nums)
        {
            ans^=i;
            ans^=a++;
        }
        return ans;
    }
};