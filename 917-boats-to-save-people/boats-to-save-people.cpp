class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(),people.end());
        int ans=0;
        int lo=0,hi=people.size()-1;
        while(lo<=hi)
        {
            if(people[lo]+people[hi]<=limit)
            {
                ++ans;
                ++lo;
                --hi;
            }
            else
            {
                ++ans;
                --hi;
            }
        }
        return ans;
    }
};