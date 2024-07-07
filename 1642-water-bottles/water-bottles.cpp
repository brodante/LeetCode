class Solution {
public:
    int numWaterBottles(int nb, int ne)
    {
        int ans=nb;
        while(nb>=ne)
        {
            int tmp=nb/ne;
            int rem=nb%ne;
            ans+=tmp;
            nb=tmp+rem;
        }
        return ans;
    }
};