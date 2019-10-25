#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            --n;
            int mod = n % 26;
            ans.insert(ans.begin(), 'A' + mod);
            n /= 26;
        };
        return ans;
    }
};
