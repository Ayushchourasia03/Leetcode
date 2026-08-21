class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> first, last, freq;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int x = nums[i];
            if(first.find(x)==first.end()){
                first[x] = i;
            }
            last[x] = i;      // keeps updating, so ends up being the last occurrence
            freq[x]++;
        }

        int degree = 0;
        for(auto& p : freq){
            degree = max(degree, p.second);
        }

        int minLen = n;
        for(auto& p : freq){
            int x = p.first;
            if(freq[x] == degree){
                int len = last[x] - first[x] + 1;
                minLen = min(minLen, len);
            }
        }

        return minLen;
    }
};