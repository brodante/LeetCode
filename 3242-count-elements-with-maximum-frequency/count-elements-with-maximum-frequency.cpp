class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        vector<int> hashh(100,0);
        int tmp=-1,ans=0;
        for(int it:nums)
        {
            ++hashh[it-1];
            tmp=max(hashh[it-1],tmp);
        }
        for(int it:hashh)
            if(it==tmp)
                ans+=tmp;
        return ans;
    }
};