class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        unordered_set<int> s1(nums1.begin(),nums1.end());
        unordered_set<int> s2(nums2.begin(),nums2.end());
        unordered_set<int> s3(nums3.begin(),nums3.end());
        unordered_set<int> res;
        for(int &i:nums1)
            if(s2.contains(i)||s3.contains(i))
                res.insert(i);
        for(int &i:nums2)
            if(s1.contains(i)||s3.contains(i))
                res.insert(i);
        for(int &i:nums3)
            if(s1.contains(i)||s2.contains(i))
                res.insert(i);
        vector<int> ans(res.begin(),res.end());
        return ans;
    }
};