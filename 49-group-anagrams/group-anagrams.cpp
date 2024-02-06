class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mpp;
        for (string s:strs)
        {
            string t=s; 
            sort(t.begin(),t.end());
            mpp[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto p:mpp) 
            ans.emplace_back(p.second);
        return ans;
    }
};