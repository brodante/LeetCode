class Solution {
public:
    int countStudents(vector<int>& st, vector<int>& sd)
    {
        deque<int> q(st.begin(),st.end());
        int i=0,cnt=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop_front();
            if(curr!=sd[i])
            {
                ++cnt;
                q.push_back(curr);
            }
            else
            {
                ++i;
                cnt=0;
            }
            if(cnt==q.size())
                break;
        }
        return q.size();
    }
};