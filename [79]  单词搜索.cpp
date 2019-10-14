#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for()
	}

private:
	bool dp(vector<vector<char>>& board, string word, int p, int x, int y, vector<vector<bool>>& visited) {
		if (is_legal(bo)!visited[x][y] && board[x][y] == word[p]) {
			visited[x][y] = true;
			for (int i = 0; i < 4; ++i) {
				dp(board, word, p + 1, x + dirx[i], y + diry[i], visited);
			}
			visited[x][y] = false;
		}
		return false;
	}
	bool is_legal(int x, int y, vector<vector<char>>& board) {
		return x >= 0 && y >= 0 && x < board[0].size() && y < board.size();
	}
	int dirx[4] = { 0,1,0,-1 };
	int diry[4] = { 1,0,-1,0 };
};