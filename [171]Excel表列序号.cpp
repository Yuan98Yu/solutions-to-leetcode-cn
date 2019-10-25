#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for (char c : s) {
            ans *= 26;
            ans += c-'A'+1;
        }
        return ans;        
    }
};
