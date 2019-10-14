#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;

        for(size_t i = 0;i < board.size(); ++i){
            for (size_t j = 0; j < board[0].size(); ++j)
            {
                bool isEdge = i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1;
                if(isEdge && board[i][j] == 'O')
                    dfs(board, i, j);
            }            
        }    

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
                
            }
        }
             
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != 'O')
            return;
        
        board[i][j] = '#';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
};
