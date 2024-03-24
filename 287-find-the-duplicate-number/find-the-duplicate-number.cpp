class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        vector<int> arr=nums;
        while(arr[0]!=arr[arr[0]])
            swap(arr[0],arr[arr[0]]);
        return arr[0];
    }
};