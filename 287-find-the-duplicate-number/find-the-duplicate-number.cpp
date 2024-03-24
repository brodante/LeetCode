class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> s;
        for(int i:nums)
        {
            if(s.contains(i))
                return i;
            s.insert(i);
        }
    return nums.size()+1;
    }
};