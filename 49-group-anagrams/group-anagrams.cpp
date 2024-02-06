class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,int> mpp;
        vector<vector<string>> ans;
        for(string it:strs)
        {
            string tmp=it;
            sort(tmp.begin(),tmp.end());
            if(mpp.contains(tmp))
                ans[mpp[tmp]].push_back(it);
            else
            {
                mpp[tmp]=ans.size();
                ans.push_back({it});
            }
        }
        return ans;
    }
};