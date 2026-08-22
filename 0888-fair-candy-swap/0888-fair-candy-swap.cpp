class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int n = aliceSizes.size();
        int m = bobSizes.size();

        int sumA = 0, sumB = 0;
        for(int i = 0; i < n; i++) sumA += aliceSizes[i];
        for(int j = 0; j < m; j++) sumB += bobSizes[j];

        int diff = (sumA - sumB) / 2;   // x - y must equal this

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(aliceSizes[i] - bobSizes[j] == diff){
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }

        return {};   // unreachable per problem guarantee, but satisfies the compiler
    }
};