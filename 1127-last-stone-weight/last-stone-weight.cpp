class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
    sort(stones.begin(), stones.end());

    while (stones.size() > 1) {

        int n = stones.size();
        int stone1 = stones[n - 1];
        int stone2 = stones[n - 2];

        stones.pop_back();
        stones.pop_back();
        
        if (stone1 != stone2) {
            int newStone = stone1 - stone2;
            auto it = std::lower_bound(stones.begin(), stones.end(), newStone);
            stones.insert(it, newStone);
        }
    }

    return stones.empty() ? 0 : stones[0];
    }
};