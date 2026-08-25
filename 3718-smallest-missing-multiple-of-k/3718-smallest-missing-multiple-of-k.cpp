class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> s;
        
        // Store all elements
        for(int x : nums) {
            s.insert(x);
        }
        
        // Check multiples of k
        for(int i = 1; ; i++) {
            
            int multiple = k * i;
            
            if(s.find(multiple) == s.end()) {
                return multiple;
            }
        }
    }
};