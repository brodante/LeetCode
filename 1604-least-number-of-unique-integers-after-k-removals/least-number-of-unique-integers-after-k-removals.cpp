class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        unordered_map<int,int> mpp;
        for(int it:arr)
            ++mpp[it];
        vector<int> tmp;
        for(pair<int,int> it:mpp)
            tmp.push_back(it.second);
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();++i)
        {
            k-=tmp[i];
            if(k<0)
                return tmp.size()-i;
        }
        return 0;
    }
};