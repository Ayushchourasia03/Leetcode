class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int k) {
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size())
            return false;                                   // 1
        if (board[r][c] != word[k]) return false;           // 2
        if (k == (int)word.size() - 1) return true;         // 3

        char saved = board[r][c];
        board[r][c] = '#';                                  // 4

        bool found = dfs(board, word, r - 1, c, k + 1) ||   // 5 up
                     dfs(board, word, r + 1, c, k + 1) ||   //   down
                     dfs(board, word, r, c - 1, k + 1) ||   //   left
                     dfs(board, word, r, c + 1, k + 1);     //   right

        board[r][c] = saved;                                // 6
        return found;                                       // 7
    }
};