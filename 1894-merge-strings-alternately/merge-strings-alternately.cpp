class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;
        int i=0;
        while(i<word1.size()||i<word2.size())
        {
            if(i<word1.size())
                ans+=word1[i];          
            if(i<word2.size())
                ans+=word2[i];
            i++;
        }
        return ans;
    }
};
