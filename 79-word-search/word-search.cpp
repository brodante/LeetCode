class Solution {
private:
    bool dfs(int r, int c, int i, vector<vector<char>>& b, string& w) {
        if (i == w.size())
            return true;
        if (r < 0 || c < 0 || r >= b.size() || c >= b[0].size() || b[r][c] != w[i])
            return false;
        
        char temp = b[r][c]; // Store the current character before modification
        b[r][c] = '*'; // Mark the cell as visited
        
        bool ans = (dfs(r + 1, c, i + 1, b, w) ||
                    dfs(r - 1, c, i + 1, b, w) ||
                    dfs(r, c + 1, i + 1, b, w) ||
                    dfs(r, c - 1, i + 1, b, w));
        
        b[r][c] = temp; // Restore the original character
        
        return ans;
    }
public:
    bool exist(vector<vector<char>>& b, string& w) {
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                if (dfs(i, j, 0, b, w))
                    return true;
            }
        }
        return false;
    }
};