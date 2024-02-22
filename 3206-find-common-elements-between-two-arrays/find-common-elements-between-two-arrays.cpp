class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> a(nums1.begin(),nums1.end());
        unordered_set<int> b(nums2.begin(),nums2.end());
        int x=0,y=0;
        for(int &i:nums1)
            if(b.contains(i))
                ++x;
        for(int &i:nums2)
            if(a.contains(i))
                ++y;
        return {x,y};
    }
};