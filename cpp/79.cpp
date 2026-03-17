class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false; 
        int pos = 0;
        vector<vector<bool>> visitados (board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size() && res != true; i++) {
            for (int j = 0; j < board[0].size() && res != true; j++) {
                if (word[pos] == board[i][j]) 
                    dfs(board, res, i, j, pos, word, visitados);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, bool& res, int i, int j, int pos, string& word, vector<vector<bool>>& visitados) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return;

        if (visitados[i][j] == true || res == true)
            return;

        if (word[pos] != board[i][j])
            return;

        if (pos == word.size() - 1) {
            res = true;
            return;
        }

        pos++;
        visitados[i][j] = true;
        dfs(board, res, i+1, j, pos, word, visitados);
        dfs(board, res, i-1, j, pos, word, visitados);
        dfs(board, res, i, j+1, pos, word, visitados);
        dfs(board, res, i, j-1, pos, word, visitados);
        visitados[i][j] = false;
    }
};