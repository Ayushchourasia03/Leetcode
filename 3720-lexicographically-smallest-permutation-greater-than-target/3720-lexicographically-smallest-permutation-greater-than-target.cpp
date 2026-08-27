class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Count characters of s
        int cnt[26] = {};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Try every position from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Make a fresh copy of the frequency array
            int temp[26];

            for (int k = 0; k < 26; k++) {
                temp[k] = cnt[k];
            }

            // Try to form target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (temp[x] == 0) {
                    possible = false;
                    break;
                }

                temp[x]--;
            }

            if (!possible) {
                continue;
            }

            // Now at position i,
            // we need the smallest character > target[i]
            int x = target[i] - 'a';

            for (int bigger = x + 1; bigger < 26; bigger++) {

                if (temp[bigger] > 0) {

                    // Take the prefix BEFORE i
                    string ans = target.substr(0, i);

                    // Put the smallest bigger character
                    ans += char('a' + bigger);

                    temp[bigger]--;

                    // Put remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {

                        while (temp[k] > 0) {
                            ans += char('a' + k);
                            temp[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};