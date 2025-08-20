class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(needle.size()>haystack.size())
            return -1;
        int ans=-1;
        for(int i=0;i<haystack.length();++i)
        {
            ans=i;
            int j=0;
            // while(haystack[i]==needle[j]&&j<needle.length())  // Original
            //     ++j;                                           // Original
            while(haystack[i+j]==needle[j]&&i+j<haystack.length()&&j<needle.length())
                ++j;
            if(j==needle.length())
                return ans;
        }
    return -1;
    }
};