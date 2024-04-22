class Solution {
private:
    void addNeighbours(queue<string> &q, string &curr, unordered_set<string> &st)
    {
        for(int i=0;i<4;++i)
        {
            char tmp=curr[i]; //backup

            char dec= tmp=='0'?'9':tmp-1;
            char inc= tmp=='9'?'0':tmp+1;

            curr[i]=dec; //test for decreased slot
            if(!st.contains(curr))
            {
                st.insert(curr);
                q.push(curr);
            }

            curr[i]=inc; //check for increased slot
            if(!st.contains(curr))
            {
                st.insert(curr);
                q.push(curr);
            }
            curr[i]=tmp;
        }
    }
public:
    int openLock(vector<string>& deadends, string target)
    {
        unordered_set<string> st(deadends.begin(),deadends.end());
        string start="0000";
        queue<string> q;
        q.push(start);
        if(st.contains("0000"))
            return -1;
        int level=0;
        while(!q.empty())
        {
            int n=q.size(); //total elements per level
            while(n--)
            {
                string curr=q.front();
                q.pop();

                if(curr==target)
                    return level;
                
                addNeighbours(q,curr,st);
            }
            ++level;
        }
        return -1;
    }
};