class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> indexed(n); // {score, original index}
        for(int i = 0; i < n; i++){
            indexed[i] = {score[i], i};
        }

        // sort descending by score
        sort(indexed.begin(), indexed.end(), greater<pair<int,int>>());

        vector<string> result(n);
        for(int rank = 0; rank < n; rank++){
            int originalIndex = indexed[rank].second;
            if(rank == 0) result[originalIndex] = "Gold Medal";
            else if(rank == 1) result[originalIndex] = "Silver Medal";
            else if(rank == 2) result[originalIndex] = "Bronze Medal";
            else result[originalIndex] = to_string(rank + 1);
        }

        return result;
    }
};