class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow=nums[0];
        int fast=nums[0];
        while(1)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow)
                break;
        }
        slow=nums[0]; //re-using slow ptr
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};