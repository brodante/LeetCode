class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        vector<pair<int,int>> tmp(score.size());
        for(int i=0;i<score.size();++i)
            tmp[i]={score[i],i};
        sort(tmp.begin(),tmp.end(),greater<pair<int,int>>());
        
        vector<string> ans(score.size());

        for(int i=0;i<tmp.size();++i)
        {
            if(i==0)
                ans[tmp[i].second]="Gold Medal";
            else if(i==1)
                ans[tmp[i].second]="Silver Medal";
            else if(i==2)
                ans[tmp[i].second]="Bronze Medal";
            else
                ans[tmp[i].second]=to_string(i+1);
        }
        return ans;
    }
};