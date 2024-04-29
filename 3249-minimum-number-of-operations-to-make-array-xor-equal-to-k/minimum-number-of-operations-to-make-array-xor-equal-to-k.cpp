class Solution {
public:
    int minOperations(vector<int>& n, int k)
    {
        for(int it:n)
            k^=it;
        return __builtin_popcount(k);
    }
};