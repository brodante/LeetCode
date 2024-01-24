class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int x,y;
        int tmp=0;
        int n=nums.size();
        n=(n*(n+1))/2;
        unordered_set<int> s;
        for(int i:nums)
        {
            if(s.contains(i))
                y=i;
            else
            {
                s.insert(i);
                tmp+=i;
            }
        }
        return {y,n-tmp};
    }
};