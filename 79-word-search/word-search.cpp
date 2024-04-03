class Solution {
private:
    bool dfs(int r, int c, int i, vector<vector<char>> &b, string &w, vector<vector<bool>> &hashh)
    {
        if(i==w.size())
            return true;
        if(r<0 || c<0 || r>=b.size() ||c>=b[0].size() || b[r][c]!=w[i] || hashh[r][c])
            return false;
        hashh[r][c]=true;
        bool ans = (dfs(r+1, c, i+1, b, w, hashh) ||
                    dfs(r-1, c, i+1, b, w, hashh) || 
                    dfs(r, c+1, i+1, b, w, hashh) || 
                    dfs(r, c-1, i+1, b, w, hashh));
        hashh[r][c]=false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& b, string &w)
    {
        vector<vector<bool>> hashh(b.size(),vector<bool>(b[0].size(),false));
        for(int i=0;i<b.size();++i)
            for(int j=0;j<b[0].size();++j)
                if(dfs(i,j,0,b,w,hashh))
                    return true;
        return false;
    }
};