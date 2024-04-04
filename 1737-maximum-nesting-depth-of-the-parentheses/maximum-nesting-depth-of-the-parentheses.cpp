class Solution {
public:
    int maxDepth(string s)
    {
        int i=-1,ans=0,tmp=0;
        while((++i)<s.size())
        {
            if(s[i]=='(')
                ++tmp;
            else if(s[i]==')')
                --tmp;
            ans=max(ans,tmp);
        }
        return ans;
    }
};