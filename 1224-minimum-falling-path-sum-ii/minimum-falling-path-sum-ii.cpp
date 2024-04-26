class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int firstmin=0, secondmin=0, pos=-1; //if we initialise INT_MAX "line add" will give overflow
        for(int i=0;i<n;++i)
        {
            int firstmin2=INT_MAX, secondmin2=INT_MAX, pos2=-1;
            for(int j=0;j<n;++j)
            {
                int tmp= (j!=pos) ? firstmin:secondmin;
                if(grid[i][j]+tmp< firstmin2) //line add
                {
                    secondmin2= firstmin2;
                    firstmin2= grid[i][j]+ tmp;
                    pos2= j;
                }
                else
                    secondmin2= min(secondmin2,grid[i][j]+ tmp);
            }
            firstmin= firstmin2;
            secondmin= secondmin2;
            pos= pos2;
        }
        return firstmin;
    }
};