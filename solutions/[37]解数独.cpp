#include <vector>
using namespace std;

class Solution {
public:
	const int N = 9;

	Solution() {
		rows_vac = vector<vector<bool>> (N, vector<bool> (N+1, true));
		cols_vac = vector<vector<bool>> (N, vector<bool> (N+1, true));
		boxes_vac = vector<vector<bool>> (N, vector<bool> (N+1, true));
	}
	
	void solveSudoku(vector<vector<char>>& board) {
		this->pboard = &board;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j)
				if ((*pboard)[i][j] != '.')
					rcd_num (i, j);
		}
		bt(0);
	}

	bool bt(int cur) {
		if (cur == N*N)
			return true;
		
		int row = cur / N;
		int col = cur % N;

		if ((*pboard)[row][col] == '.') {
			for (int num = 1; num <= N; ++num){
				if (could_place (num, row, col)) {
					place_num (num, row, col);
					bool rst = bt (cur + 1);
					if (rst)
						return true;
					else
						rmv_num (row, col);
				}
			}
			return false;
		}
		else {
			return bt (cur + 1);
		}
	}

private:
	vector<vector<char>> * pboard;
	vector<vector<bool>> rows_vac;
	vector<vector<bool>> cols_vac;
	vector<vector<bool>> boxes_vac;

	bool could_place(int num, int row, int col) {
		int idx = (row/3) * 3 + col/3;
		return rows_vac[row][num] && cols_vac[col][num] && boxes_vac[idx][num];
	}

	void place_num(int num, int row, int col) {
		(*pboard)[row][col] = '0' + num;
		rcd_num (row, col);
	}

	void rcd_num(int row, int col) {
		int num = (*pboard)[row][col] - '0';
		int idx = (row/3) * 3 + col/3;
		rows_vac[row][num] = cols_vac[col][num] = boxes_vac[idx][num] = false;
	}
	
	void rmv_num(int row, int col) {
		int num = (*pboard)[row][col] - '0';
		(*pboard)[row][col] = '.';
		int idx = (row/3) * 3 + col/3;
		rows_vac[row][num] = cols_vac[col][num] = boxes_vac[idx][num] = true;
	}
};