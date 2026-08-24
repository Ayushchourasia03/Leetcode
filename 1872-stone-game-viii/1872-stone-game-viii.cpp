class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> cum(n);
        cum[0] = stones[0];
        for (int i = 1; i < n; i++) cum[i] = cum[i - 1] + stones[i];

        long long D = 0;                      // D[n-1] = 0
        long long suffixMax = cum[n - 1] - D;  // term for j = n-1

        for (int i = n - 2; i >= 0; i--) {
            D = suffixMax;                     // D[i] = max_{j>i} (cum[j] - D[j])
            long long term = cum[i] - D;        // this state's own term, for use by D[i-1]
            suffixMax = max(suffixMax, term);
        }
        return D;   // D[0]
    }
};