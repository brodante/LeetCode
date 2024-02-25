class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string ans1,ans2,ans;
        for(char it:word1)
            if(isalpha(it))
                ans1+=it;
        for(char it:word2)
            if(isalpha(it))
                ans2+=it;
        int i=0;
        while(i<ans1.size()||i<ans2.size())
        {
            if(i<ans1.size())
                ans+=ans1[i];          
            if(i<ans2.size())
                ans+=ans2[i];
            i++;
        }
        return ans;
    }
};
