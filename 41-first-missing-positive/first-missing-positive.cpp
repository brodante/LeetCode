class Solution {
public: 
    int firstMissingPositive(vector<int>& nums)
    {
    int n=nums.size();
    // Step 1: Build the hash array
    vector<bool> hashh(n,false);
    for(int it:nums)
    {
        if(1<=it&&it<=n)
        {
            hashh[it-1]=true;
        }
    }
    // Step 2: Find the first missing positive
    for(int i=0;i<n;++i)
    {
        if(!hashh[i])
        {
            return i+1;
        }
    }
    // If all numbers from 1 to n are present, return n+1
    return n+1;
}
};