class Solution {
public:
    string maximumOddBinaryNumber(string s)
    {
        int hashh[2];
        for(char it:s)
            ++hashh[it-'0'];        
        string ans;
        for(int i=0;i<hashh[1]-1;++i)
            ans+='1';
        for(int i=0;i<hashh[0];++i)
            ans+='0';
        ans+='1';
        return ans;
    }
};