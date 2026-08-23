class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber > 0){
            columnNumber--;                      // shift 1-26 down to 0-25
            char letter = 'A' + (columnNumber % 26);
            result = letter + result;            // prepend, since we build least-significant digit first
            columnNumber = columnNumber / 26;
        }
        return result;
    }
};