
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[j].set(grid[i][j]);
                    continue;
                }

                bitset<1024> cur;
                int val = grid[i][j];

                // Reachable XOR values from above
                for (int x = 0; x < 1024; x++) {
                    if (dp[j][x]) {
                        cur.set(x ^ val);
                    }
                }

                // Reachable XOR values from the left
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[j - 1][x]) {
                            cur.set(x ^ val);
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};
