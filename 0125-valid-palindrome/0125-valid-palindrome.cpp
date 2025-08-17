class Solution {
public:
    bool isPalindrome(string s)
    {
        string tmp="";
        int i=0;
        while(i<s.length())
        {
            if(s[i]<='z'&&s[i]>='a')
                tmp+=char(s[i]);
            if(s[i]<='Z'&&s[i]>='A')
                tmp+=char(s[i]+32);
            if(s[i]<='9'&&s[i]>='0')
                tmp+=char(s[i]);
            ++i;
        }
        int h=0;
        i=tmp.length()-1;
        while(h<=i)
        {
            if(tmp[h++]==tmp[i--])
                continue;
            else
                return false;
        }
        return true;
    }
};