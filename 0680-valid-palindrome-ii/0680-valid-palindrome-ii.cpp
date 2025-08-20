class Solution {

/*
iterate from both sides
if mismatch
do a quick check by skipping s[i] ie from s[i+1].
do another quick check by skipping s[j] ie from s[j-1].
if either gives a palindrome then return true.
if no mismatch found at all, then already a palindrome.*/

private:
    bool checkPalindrome(string s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i]==s[j])
                ++i,--j;
            else
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s)
    {
        int i=0,j=s.length()-1;
        int ans1=0;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                ++i;
                --j;
            }
            else
            {
                int i1=i,j1=j;
                bool ans1=checkPalindrome(s,i1+1,j1);
                bool ans2=checkPalindrome(s,i1,j1-1);

                if(ans1||ans2)
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};