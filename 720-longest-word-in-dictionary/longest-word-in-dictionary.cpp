class Solution {
public:
    string longestWord(vector<string>& words)
    {
        sort(words.begin(),words.end());
        unordered_set<string> st;
        string ans;
        for(string w:words)
        {
            if(w.size()==1||st.contains(w.substr(0,w.size()-1)))
            {
                ans=w.size()>ans.size()?w:ans;
                st.insert(w);
            }
        }
        return ans;
    }
};