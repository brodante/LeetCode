class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> hashh(26,0);
        int tmp=0;
        for(char it:tasks)
        {
            ++hashh[it-'A'];
            tmp=max(tmp,hashh[it-'A']);
        }
        int ans=(tmp-1)*(n+1);
        for(int it:hashh)
            if(it==tmp)
                ++ans;
        return max(static_cast<int>(tasks.size()), ans);
    }
};