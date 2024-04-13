class Solution {
private:
    int largestRectangleArea(vector<int>& heights) // max Histogram area
    {
        int n=heights.size();
        if(!n)
            return 0;
        int ans=0;
        vector<int> left(n);
        vector<int> right(n);
        left[0]=-1;
        right[n-1]=n;

        for(int i=1;i<n;++i)
        {
            int tmp=i-1;
            while(tmp>=0&&heights[tmp]>=heights[i])
                tmp=left[tmp];
            left[i]=tmp;
        }

        for(int i=n-1;i>=0;--i)
        {
            int tmp=i+1;
            while(tmp<n&&heights[tmp]>=heights[i])
                tmp=right[tmp];
            right[i]=tmp;
        }

        for(int i=0;i<n;++i)
        {
            int y=right[i]-left[i]-1;
            //cout<<left[i]<<"&"<<right[i]<<' ';
            //-1&1 -1&6 1&4 2&4 1&6 4&6 
            ans=max(ans,heights[i]*y);
        }

        return ans;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& m)
    {
        vector<vector<int>> tmp(m.size(),vector<int>(m[0].size()));
        for(int i=0;i<m.size();++i)
            for(int j=0;j<m[0].size();++j)
                tmp[i][j]=m[i][j]-'0';
        int ans=0;
        for(int i=0;i<m.size()-1;++i)
        {
            for(int j=0;j<m[0].size();++j)
            {
                if(tmp[i][j]!=0&&tmp[i+1][j]!=0)
                    tmp[i+1][j]+=tmp[i][j];
            }
        }
        for(int i=0;i<m.size();++i)
            ans=max(ans,largestRectangleArea(tmp[i]));
    return ans;
    }
};