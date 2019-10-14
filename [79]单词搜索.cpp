#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int x = 0; x < board.size(); ++x) {
			for (int y = 0; y < board[0].size(); ++y) {
				if (dp(board, word, 0, x, y, visited))
					return true;
			}
		}
		return false;
	}

private:
	bool dp(vector<vector<char>>& board, string word, int p, int x, int y, vector<vector<bool>>& visited) {
		if (is_legal(x, y, board) && !visited[x][y] && board[x][y] == word[p]) {
			if (p == word.size() - 1)
				return true;
			visited[x][y] = true;
			for (int i = 0; i < 4; ++i) {
				if (dp(board, word, p + 1, x + dirx[i], y + diry[i], visited))
					return true;
			}
			visited[x][y] = false;
		}
		return false;
	}
	bool is_legal(int x, int y, vector<vector<char>>& board) {
		return x >= 0 && y >= 0 && x < board.size() && y < board[0].size();
	}
	int dirx[4] = { 0,1,0,-1 };
	int diry[4] = { 1,0,-1,0 };
};