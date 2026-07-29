class Solution {
public:
    static const int CAP = 1000000;

    long long combCap(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long res = 1;
        for (int i = 1; i <= r; i++) {
            long long num = n - r + i;
            long long den = i;

            long long g = std::gcd(num, den);
            num /= g;
            den /= g;

            g = std::gcd(res, den);
            res /= g;
            den /= g;

            res *= num;
            res /= den;

            if (res > CAP) return CAP + 1;
        }
        return res;
    }

    long long countWays(vector<int> &half) {
        int rem = 0;
        for (int x : half) rem += x;

        long long ways = 1;
        for (int x : half) {
            if (x == 0) continue;
            ways *= combCap(rem, x);
            if (ways > CAP) return CAP + 1;
            rem -= x;
        }
        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;
        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            halfLen += half[i];
            if (freq[i] % 2) mid = char('a' + i);
        }

        if (countWays(half) < k) return "";

        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};