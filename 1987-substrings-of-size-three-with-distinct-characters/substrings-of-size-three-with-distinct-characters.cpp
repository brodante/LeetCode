class Solution {
public:
    int countGoodSubstrings(string s)
    {
        if(s.size()<3)
            return 0;
        char a,b,c;
        int i=0,j=2,ans=0;
        a=s[0];
        b=s[1];
        while(j<s.size())
        {
            c=s[j];
            if(a!=b&&b!=c&&a!=c)
                ++ans;
            a=s[++i];
            b=s[i+1];
            c=s[++j];
        }
        return ans;
    }
};