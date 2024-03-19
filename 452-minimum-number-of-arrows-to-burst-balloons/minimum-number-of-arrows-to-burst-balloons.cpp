class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int ans=1;
        //sort(points.begin(),points.end(),-1);
        sort(points.begin(),points.end(),[](vector<int> a,vector<int> b)
        {
            return a[1]<b[1]; // Sort by end position
        });
        int tmp=points[0][1];
        for(int i=1;i<points.size();++i)
        {
            if(tmp>=points[i][0])
                tmp=min(tmp,points[i][1]);
            else
            {
                tmp=points[i][1];
                ++ans;
            }
        }
        return ans;
    }
};