class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {

            int pos = -1;

            // Find nums1[i] in nums2
            for (int j = 0; j < m; j++) {
                if (nums2[j] == nums1[i]) {
                    pos = j;
                    break;
                }
            }

            int greater = -1;

            // Search to the right of that position
            for (int j = pos + 1; j < m; j++) {
                if (nums2[j] > nums1[i]) {
                    greater = nums2[j];
                    break;
                }
            }

            ans.push_back(greater);
        }

        return ans;
    }
};