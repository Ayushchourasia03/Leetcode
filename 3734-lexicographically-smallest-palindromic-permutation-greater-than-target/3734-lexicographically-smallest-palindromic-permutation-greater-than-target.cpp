#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check if palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Characters needed in left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string left = "";

        for (int pos = 0; pos < n / 2; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back('a' + c);

                // Build largest possible remaining left half
                string temp = left;

                for (int x = 25; x >= 0; x--) {
                    temp += string(half[x], 'a' + x);
                }

                // Build palindrome
                string right = temp;
                reverse(right.begin(), right.end());

                string candidate = temp;

                if (mid)
                    candidate += mid;

                candidate += right;

                // If possible, keep this character
                if (candidate > target) {
                    break;
                }

                // Otherwise undo
                left.pop_back();
                half[c]++;
            }

            if (left.size() != pos + 1)
                return "";
        }

        // Construct final answer
        string right = left;
        reverse(right.begin(), right.end());

        string ans = left;

        if (mid)
            ans += mid;

        ans += right;

        return ans > target ? ans : "";
    }
};