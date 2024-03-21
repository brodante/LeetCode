class Solution {
public:
    string reorganizeString(string s)
    {
        int tmp=0;
        vector<int> hashh(26,0);
        for(char c:s) 
            if(++hashh[c-'a']>hashh[tmp])
                tmp=c-'a';
        if(2*hashh[tmp]-1>s.size())
            return "";
        int i=0;
        while(hashh[tmp]>0)
        {
            s[i]=(char)tmp+'a';
            --hashh[tmp];
            i+=2;
        }
        for(int j=0;j<26;++j)
        {
            while(hashh[j]>0)
            {
                if(i>=s.size())
                    i=1;
                s[i]=(char)j+'a';
                hashh[j]--;
                i=i+2;
            }
        }
        return s;
    }
};