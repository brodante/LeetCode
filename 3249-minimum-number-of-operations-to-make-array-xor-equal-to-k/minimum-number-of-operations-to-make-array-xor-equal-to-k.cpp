class Solution {
public:
    int minOperations(vector<int>& n, int k)
    {
        int tmp=0;
        for(int it:n)
            tmp^=it;
        int ans=0;
        while(k!=0 || tmp!=0)
        {
            if((k%2)!=(tmp%2))
                ++ans;
            k/=2;
            tmp/=2;
        }
        return ans;
    }
};