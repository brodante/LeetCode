class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
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
            ans=max(ans,heights[i]*y);
        }

        return ans;
        
    }
};