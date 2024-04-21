class Solution {
private:
void dfs(int i, int j, vector<vector<int>> &tmp, int &a1, int &a2)
    {

        int r=tmp.size();
        int c=tmp[0].size();

        if(i>=0&&i<r&&j>=0&&j<c&&tmp[i][j]==1)
        {
            a1=max(a1,i);
            a2=max(a2,j);
            tmp[i][j]=0;

            dfs(i, j+1, tmp, a1, a2); //connected farm lands go brrrrrr X again lmao
            dfs(i, j-1, tmp, a1, a2);
            dfs(i+1, j, tmp, a1, a2);
            dfs(i-1, j, tmp, a1, a2);
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        int r=land.size();
        int c=land[0].size();
        vector<vector<int>> ans;

        //vector<vector<bool>> tmp(r,vector<bool>(c,0)); //copy of grid we can delete farm lands from tmp

        //for(int i=0;i<r;++i)
        //    for(int j=0;j<c;++j)
        //        if(land[i][j]==1)
        //            tmp[i][j]=1; //BRO I WAS AT 1586ms and beating 5% sol now im at 80% 87ms fr

        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(land[i][j]==1)
                {
                    int a1=i,a2=j; //s
                    dfs(i,j,land,a1,a2);
                    ans.push_back({i,j,a1,a2});
                }
        return ans;
    }
}; 