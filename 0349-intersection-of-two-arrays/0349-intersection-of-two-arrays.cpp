class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for (int x : nums2) {
            if (s.find(x) != s.end()) {
                ans.push_back(x);
                s.erase(x);  // Prevent duplicates in the answer
            }
        }

        return ans;
    }
};