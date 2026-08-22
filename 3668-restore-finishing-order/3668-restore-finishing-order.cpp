class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        vector<int> pos(n + 1, 0);   // pos[id] = finishing position

        for(int i = 0; i < n; i++){
            pos[order[i]] = i;
        }

        sort(friends.begin(), friends.end(), [&](int a, int b){
            return pos[a] < pos[b];
        });

        return friends;
    }
};