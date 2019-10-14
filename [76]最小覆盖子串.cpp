#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /*
    * 法1：滑动窗口
    */
    string minWindow(string s, string t) {
        map<char, int> strT_c2i_map;
        map<char, int> window_c2i_map;

        vector<int> rcd_ll(2);      // left:int, length:int
        rcd_ll[0] = -1, rcd_ll[1] = s.length() + 1;
        for (char c : t) {
            if (strT_c2i_map.find(c) == strT_c2i_map.end() ){
                strT_c2i_map[c] = 1;
                window_c2i_map[c] = 0;
            }

            else
                ++strT_c2i_map[c];
        }

        int left = 0, right = -1;
        while (left <= s.length() - t.length()) {
            if (is_cover(strT_c2i_map, window_c2i_map)) {
                if(right - left + 1 < rcd_ll[1]) {
                    rcd_ll[0] = left;
                    rcd_ll[1] = right - left + 1;
                }
                --window_c2i_map[s[left]];
                ++left;
            }
            else {
                ++right;
                if (right >= s.length())
                    break;
                if (strT_c2i_map.find(s[right]) != strT_c2i_map.end()){
                    ++window_c2i_map[s[right]];
                }
            }
        }

        string ans;
        if (rcd_ll[0] != -1)
            ans = s.substr(rcd_ll[0], rcd_ll[1]);
        return ans;
    }
private:
    bool is_cover(const map<char, int>& t, const map<char, int>& window) {
        for (auto it = t.begin(); it != t.end(); ++it) {
            if (window.find(it->first) == window.end() || window.find(it->first)->second < it->second)
                return false;
        }
        return true;
    }
};