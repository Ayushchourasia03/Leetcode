class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string result = "";
        
        // Iterate over each character position using first string as reference
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            
            // Compare this character with all other strings
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return result;
                }
            }
            
            result += ch;
        }
        
        return result;
    }
};