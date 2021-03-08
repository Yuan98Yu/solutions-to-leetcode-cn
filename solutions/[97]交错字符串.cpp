#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        if(s1.empty() || s2.empty())
            return s1 == s3 || s2 == s3;

        vector<vector<bool>> dp(s1.size()+1, vector<bool> (s2.size()+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= s2.size(); ++j){
            if (dp[0][j-1] && s2[j-1] == s3[j-1])
                dp[0][j] = true;
        }
        for (int i = 1; i <= s1.size(); ++i){
            if (dp[i-1][0] && s1[i-1] == s3[i-1])
                dp[i][0] = true;
        }
        for (int i = 1; i <= s1.size(); ++i){
            for (int j = 1; j <= s2.size(); ++j){
                if ( (dp[i-1][j] && s3[i+j-1] == s1[i-1]) || (dp[i][j-1] && s3[i+j-1] == s2[j-1]) )
                    dp[i][j] = true;
            }
        }

        return dp[s1.size()][s2.size()];
    }
};
