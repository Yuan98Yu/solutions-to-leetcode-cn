#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		set<char> line;
		vector<set<char>> columns(9);
		vector<set<char>> box(3);

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char now = board[i][j];
				if (now == '.')
					continue;

				int box_idx = j / 3;
				if (line.find(now) != line.end() || columns[j].find(now) != columns[j].end() || box[box_idx].find(now) != box[box_idx].end())
					return false;

				line.insert(now);
				columns[j].insert(now);
				box[box_idx].insert(now);
			}
			line.clear();
			if (i % 3 == 2)
				for (set<char>& per_box : box)
					per_box.clear();
		}

		return true;
	}
};