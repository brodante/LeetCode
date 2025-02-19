#include <vector>
#include <cmath>

class Solution {
public:
    int kthFactor(int n, int k) {
        std::vector<int> factors;
        int sqrtN = sqrt(n);

        // Collect factors up to sqrt(n)
        for (int i = 1; i <= sqrtN; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
            }
        }

        // Determine the total number of factors
        int size = factors.size();
        bool isPerfectSquare = (sqrtN * sqrtN == n);
        int totalFactors = isPerfectSquare ? (2 * size - 1) : (2 * size);

        // If k is greater than the total number of factors, return -1
        if (k > totalFactors) {
            return -1;
        }

        // If k is in the first half, return factors[k - 1]
        if (k <= size) {
            return factors[k - 1];
        }

        // If k is in the second half, adjust for perfect squares
        if (isPerfectSquare) {
            return n / factors[size - (k - size) - 1];
        } else {
            return n / factors[size - (k - size)];
        }
    }
};