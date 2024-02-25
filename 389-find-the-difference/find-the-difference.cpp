class Solution {
public:
    char findTheDifference(string s, string t)
    {
        s+=t;
        int ans=0;
        for(char it:s)
            ans^=it;
        return ans;
    }
};