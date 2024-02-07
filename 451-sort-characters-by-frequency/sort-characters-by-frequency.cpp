class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        for(char c:s)
            mpp[c]++;
        map<int, string> mpp1;
        for(auto v:mpp)
        {
            char c=v.first;
            int n=v.second;
            mpp1[n]+=string(n,c);
        }
        string ans;
        for(auto it=mpp1.rbegin();it!=mpp1.rend();++it)
            ans += it->second;
        return ans;
    }
};