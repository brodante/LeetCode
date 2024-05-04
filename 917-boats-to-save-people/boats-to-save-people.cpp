class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(),people.end(),greater());
        int i=0,j=people.size()-1;
        while(i<=j)
        {
            if(people[j]+people[i]<=limit)
                --j;
            ++i;
        }
        return i;
    }
};