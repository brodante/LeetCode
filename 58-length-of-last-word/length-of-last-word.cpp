class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int n=s.size();
        int i=0,j=n;
        bool flag=0;
        for(int i=n;i>=0;i--)
        {
            if(isalpha(s[i])&&!flag)
                j=i,flag=1;
            if(flag&&s[i]==' ')
                return j-i;
        }
    return j+1;
    }
};