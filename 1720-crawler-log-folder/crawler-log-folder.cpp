class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int ans=0;
        for(string &s:logs)
        {
            if(s=="../")
            {
                if(ans>0)
                    --ans;
            }
            else if(s=="./")
                continue;
            else
                ++ans;
        }
        return ans;
    }
};