class Solution {
public:
    long long largestPerimeter(vector<int>& nums)
    {
        vector<int> tmp(nums);
        sort(tmp.begin(),tmp.end());
        long long ans=0;
        for(int i=0;i<tmp.size();++i)
            ans+=tmp[i];
        for(int i=tmp.size()-1;i>0;--i)
            {
                ans-=tmp[i];
                if(ans>tmp[i])
                   return ans+tmp[i]; 
            }
        return -1;
    } //1 2 4 7 12 24 74
};