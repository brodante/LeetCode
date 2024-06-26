class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int neighbor= 0;
        int island= 0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j])
                {
                    ++island;
                    if(i&&grid[i-1][j]==1)
                        ++neighbor;
                    if(j&&grid[i][j-1]==1)
                        ++neighbor;
                }
            }
        }
        return island*4 - 2*neighbor; // each island has 4 sides perimeter 
    }                                 // if 2 islands are adjacent(neighbours)
};                                    // then we subtract the touching side, i.e. 2 times neighbour