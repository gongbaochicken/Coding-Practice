//Word Search
/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.*/

//Solution: DFS
class Solution {
public:
    //bfs to search if we can find word(index).
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int index){
        if(board[i][j] != word[index]) return false;
        if(index+1 == word.size()) return true;
        int m = board.size(), n = board[0].size();
        visited[i][j] = true;
        if(i > 0 && !visited[i-1][j] && dfs(board, visited, i-1, j, word, index+1)) return true;
        if(i+1 < m && !visited[i+1][j] && dfs(board, visited, i+1, j, word, index+1)) return true;
        if(j > 0 && !visited[i][j-1] && dfs(board, visited, i, j-1, word, index+1)) return true;
        if(j+1 < n && !visited[i][j+1] && dfs(board, visited, i, j+1, word, index+1)) return true;
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0 || word.size() == 0) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
                if(dfs(board, visited, i, j, word, 0)) return true;
        	}
        }
        return false;
    }
};

//Word Search 2 ===>Trie