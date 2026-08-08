class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        // last[j] = latest index in word1
        // that can match word2[j]
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans(m);

        bool usedMismatch = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Normal matching
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;
                usedMismatch = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};