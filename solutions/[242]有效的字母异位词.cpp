#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (char c : s)
            count[c-'a'] += 1;
        for (char c : t)
            count[c-'a'] -= 1;

        for (int n : count)
            if (n != 0)       
                return false;
        return true;
    }
};
