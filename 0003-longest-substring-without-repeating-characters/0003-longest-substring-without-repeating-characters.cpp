class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            if (last[ch] >= left) {
                left = last[ch] + 1;
            }

            last[ch] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};