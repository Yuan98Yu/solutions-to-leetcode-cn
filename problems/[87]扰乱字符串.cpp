#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    * 穷举
    */
    bool isScramble(string s1, string s2) {
        if (s1.empty())
            return false;
        if (s1 == s2)
            return true;

        string ss1(s1);
		string ss2(s2);
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		if (ss1 != ss2) {
			return false;
		}

        for (int i = 1; i < s1.length(); ++i) {
            if ( (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                || (isScramble(s1.substr(i), s2.substr(0, s2.length() - i)) && isScramble(s1.substr(0, i), s2.substr(s2.length()-i)))
            )
                return true;
        }
        return false;
    }

    /*
    * 动态规划
    */
    bool isScramble2(string s1, string s2) {

    }
};