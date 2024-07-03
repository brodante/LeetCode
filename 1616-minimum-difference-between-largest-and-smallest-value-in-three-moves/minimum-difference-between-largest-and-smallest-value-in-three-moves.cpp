class Solution {
public:
    int minDifference(vector<int>& nums)
    {
         if (nums.size() <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = min({
            nums[n-1] - nums[3],  // Remove the three smallest
            nums[n-2] - nums[2],  // Remove two smallest, one largest
            nums[n-3] - nums[1],  // Remove one smallest, two largest
            nums[n-4] - nums[0]   // Remove the three largest
        });

        return ans;
    }
};