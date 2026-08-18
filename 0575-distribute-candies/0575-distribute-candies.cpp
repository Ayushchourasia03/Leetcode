class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());

        return min((int)st.size(), (int)candyType.size() / 2);
    }
};