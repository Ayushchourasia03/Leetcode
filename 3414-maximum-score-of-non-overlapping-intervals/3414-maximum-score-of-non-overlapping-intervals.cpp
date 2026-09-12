class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {l, r, weight, original index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending point
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        // Store all ending points for binary search
        vector<int> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        // dp[k] = {maximum score, lexicographically smallest indices}
        vector<pair<long long, vector<int>>> dp(5);

        for (int k = 0; k <= 4; k++)
            dp[k] = {0, {}};

        for (int i = 0; i < n; i++) {
            vector<pair<long long, vector<int>>> ndp = dp;

            // Find last interval whose end < current start
            int p = lower_bound(ends.begin(), ends.end(), a[i][0])
                    - ends.begin() - 1;

            // dpBefore[k] should represent intervals up to p
            // We need a separate prefix DP, so handle below.
        }

        // prefixDP[i][k] = answer using first i sorted intervals
        vector<vector<pair<long long, vector<int>>>> prefix(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                prefix[i][k] = {0, {}};
            }
        }

        for (int i = 1; i <= n; i++) {
            // Don't take interval i-1
            prefix[i] = prefix[i - 1];

            int start = a[i - 1][0];

            // Number of intervals ending before start
            int p = lower_bound(ends.begin(), ends.end(), start)
                    - ends.begin();

            // p is the number of compatible intervals
            for (int k = 1; k <= 4; k++) {
                if (p >= 0) {
                    auto candidate = prefix[p][k - 1];

                    candidate.first += a[i - 1][2];
                    candidate.second.push_back(a[i - 1][3]);

                    // Keep indices sorted for lexicographical comparison
                    sort(candidate.second.begin(), candidate.second.end());

                    if (candidate.first > prefix[i][k].first ||
                        (candidate.first == prefix[i][k].first &&
                         candidate.second < prefix[i][k].second)) {
                        prefix[i][k] = candidate;
                    }
                }
            }
        }

        // Find maximum score among <= 4 intervals
        pair<long long, vector<int>> ans = {0, {}};

        for (int k = 0; k <= 4; k++) {
            if (prefix[n][k].first > ans.first ||
                (prefix[n][k].first == ans.first &&
                 prefix[n][k].second < ans.second)) {
                ans = prefix[n][k];
            }
        }

        return ans.second;
    }
};