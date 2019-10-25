#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        __dp_is_palindrom = vector<vector<bool>> (s.length(), vector<bool> (s.length()));
        __dp_ans = vector<vector<int>> (s.length(), vector<int> (s.length(), -1));
        for (int len = 1; len <= s.length(); ++len) {
            for (int i = 0; i <= s.length() - len; ++i) {
                int j = i + len - 1;
                __dp_is_palindrom[i][j] = s[i] == s[j] && (len < 3 || __dp_is_palindrom[i + 1][j - 1]);
            }
        }

        return __bt(0, 0, s.length()-1);
    }

private:
    vector<vector<bool>> __dp_is_palindrom;
    vector<vector<int>> __dp_ans;
    int __bt(int ans, int left, int right){
        if (left >= right) {
			return 0;
		}
        if (__dp_ans[left][right] >= 0)
            return __dp_ans[left][right];

        int tmp;
        if (__is_palindrome(left, right) )
            tmp = 0;
        else {
            tmp = right - left;
            for (int r = left; r <= right-1; ++r) {
                if (__is_palindrome (left, r) ) {
                    tmp = min(tmp, 1 + __bt(0, r+1, right) );
                }
            }
        }
        __dp_ans[left][right] = ans + tmp;
        return __dp_ans[left][right];
    }

    bool __is_palindrome(int left, int right) {
        return __dp_is_palindrom[left][right];
    } 
};