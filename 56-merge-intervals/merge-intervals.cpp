class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itr)
    {
        if(!itr.size())
            return itr;
        sort(itr.begin(),itr.end());
        vector<vector<int>> ans;
        vector<int> tmp=itr[0];
        for(auto it:itr)
        {
            if(it[0]<=tmp[1])
                tmp[1]=max(it[1],tmp[1]);
            else
            {
                ans.emplace_back(tmp);
                tmp=it;
            }
        }
        ans.emplace_back(tmp);
        return ans;
    }
};