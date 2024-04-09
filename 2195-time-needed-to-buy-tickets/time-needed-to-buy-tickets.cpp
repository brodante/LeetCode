class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k)
    {
        int tmp=0;
        for(int i=0;i<k;++i)
                tmp+=min(t[k],t[i]);
        for(int i=k;i<t.size();++i)
        {
            if(t[i]<t[k])
                tmp+=min(t[k],t[i]);
            else
                tmp+=t[k]-1;

        }
        return tmp+1; //+1 for the kth person's last ticket
    }
};