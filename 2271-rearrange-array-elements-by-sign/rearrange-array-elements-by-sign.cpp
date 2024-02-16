class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> v1,v2,ans;
        for(int i:nums)
            i>0?v1.push_back(i):v2.push_back(i);
        for(int i=0;i<v2.size();++i)
        {
            ans.push_back(v1[i]);
            ans.push_back(v2[i]);
        }
        return ans;
    }
};