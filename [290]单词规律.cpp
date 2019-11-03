#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs = split_string(str, " ");
        if (pattern.length() != strs.size())
            return false;

        map<char, string> p2s;
        map<string, char> s2p;
        for (int i = 0; i < pattern.length(); ++i) {
            if (p2s.find(pattern[i]) == p2s.end() && s2p.find(strs[i]) == s2p.end() ) {
                p2s[pattern[i]] = strs[i];
                s2p[strs[i]] = pattern[i];
            }
            else if (p2s[pattern[i]] != strs[i])
                return false;
        }
        return true;
    }

    vector<string> split_string(const string& s, const string& c)
    {   
        vector<string> v;
        size_t pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));
        
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
        return v;
    }
};
