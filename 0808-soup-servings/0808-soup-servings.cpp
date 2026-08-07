class Solution {
public:
    double dp[205][205];
    bool vis[205][205];

    double solve(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;

        if (vis[a][b]) return dp[a][b];
        vis[a][b] = true;

        return dp[a][b] = 0.25 * (
            solve(max(0, a - 4), b) +
            solve(max(0, a - 3), max(0, b - 1)) +
            solve(max(0, a - 2), max(0, b - 2)) +
            solve(max(0, a - 1), max(0, b - 3))
        );
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0;

        memset(vis, false, sizeof(vis));

        int m = (n + 24) / 25;

        return solve(m, m);
    }
};