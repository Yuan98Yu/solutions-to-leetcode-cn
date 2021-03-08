#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct memo_rcd {
    int distance;
    bool is_ref;
    memo_rcd () {
        is_ref = false;
    }
} ;

class Solution {
public:
    /*
    * 法1：穷举
    */
    int minDistance(string word1, string word2) {      
        if (word1[0] == word2[0])
            return minDistance(word1.substr(1), word2.substr(1));
        else{
            return 1 + min( minDistance(word1.substr(1), word2.substr(1)), min( minDistance(word1.substr(1), word2), minDistance(word1, word2.substr(1)) ) );
        }
    }

    /*
    * 法2：优化穷举，带备忘录的动态规划（递归）
    */
    int minDistance(string word1, string word2) {
        if (word1.empty() || word2.empty() ){
            return word1.length() + word2.length();
        }
        vector< vector< struct memo_rcd> > memo(word1.length()+1, vector<struct memo_rcd> (word2.length()+1) );
        return dp(word1, word2, 0, 0, memo);
    }

   int dp(const string& word1, const string& word2, int i, int j, vector< vector<struct memo_rcd> >& memo) {
        if (memo[i][j].is_ref) {
            return memo[i][j].distance;
        }

        int distance;
        if (word1.length() == i || word2.length() == j ) {
             distance = word1.length() + word2.length() - i - j;
        }
        else{
            if (word1[i] == word2[j]) {
                distance = dp(word1, word2, i+1, j+1, memo);
            }
            else {
                // 分别为： 编辑word1[i],删除word1[i],在word1[i]处添加word2[j]
                distance = min( min( dp(word1, word2, i+1, j+1, memo), dp(word1, word2, i+1, j, memo)),
                            dp(word1, word2, i, j+1, memo));
            }
        } 
        memo[i][j].distance = distance;
        memo[i][j].is_ref = true;
        return distance;
   }
};