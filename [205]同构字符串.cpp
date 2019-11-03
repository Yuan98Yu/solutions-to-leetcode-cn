#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length() )
            return false;

        map<char, char> s2t;
        map<char, char> t2s;
        for (int i = 0; i < s.length(); ++i) {
            if (s2t.find(s[i]) == s2t.end() && t2s.find(t[i]) == t2s.end()) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            else if (s2t[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
