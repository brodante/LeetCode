class Solution {
public:
    int removeAlmostEqualCharacters(string word)
    {
        int i=1,ans=0;
        while(i<word.size())
        {
            if(word[i-1]==word[i]||char(word[i]+1)==word[i-1]||char(word[i-1]+1)==word[i])
                ++ans,i+=2;
            else
                ++i;
        }
        return ans;
    }
};