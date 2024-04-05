class Solution {
private:
    bool isEqual(char a, char b)
    {
        if(a+32==b||b+32==a)
            return true;
        return false;
    }

public:
    string makeGood(string s)
    {
        string ans;
        stack<char> tmp;
        for(char c:s)
        {
            if(!tmp.empty()&&isEqual(c,tmp.top()))
                tmp.pop();
            else
                tmp.push(c);
        }

        while(!tmp.empty())
        {
            ans.push_back(tmp.top());
            tmp.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};