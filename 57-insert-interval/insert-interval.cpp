class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& itr)
    {
        //if(!itr.size())
        //    return itr;
        //sort(itr.begin(),itr.end());
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
public:
    vector<vector<int>> insert(vector<vector<int>>& itr, vector<int>& ni)
    {
        vector<vector<int>> tmp;
        if(itr.size()==0&&ni.size()==0)
            return itr;
        else if(itr.size()==0&&ni.size()!=0)
        {
            tmp.emplace_back(ni);
            return tmp;
        }
        else if(itr.size()!=0&&ni.size()==0)
            return itr;
        bool flag=1;
        for(auto it:itr)
        {
            if(it[0]<ni[0])
                tmp.emplace_back(it);
            else if(flag)
            {
                tmp.emplace_back(ni);
                flag=0;
                tmp.emplace_back(it);
            }
            else
                tmp.emplace_back(it);
        }
        if(itr[itr.size()-1][0]<=ni[0])
            tmp.emplace_back(ni);
        //tmp.emplace_back(itr[itr.size()-1]);
        for(auto it:tmp)
            cout<<"["<<it[0]<<","<<it[1]<<"],";
        return merge(tmp);
    }
};