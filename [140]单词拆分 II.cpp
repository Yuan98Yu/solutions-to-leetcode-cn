#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(const string& s, vector<string>& wordDict) {
        __words = set<string> (wordDict.begin(), wordDict.end());

        return __dfs (s, 0);
    }
private:
    set<string> __words;
    map<int, vector<string> > __m;

    vector<string> __dfs(const string& s, int start) {
        if (__m.find(start) != __m.end()) {
            return __m[start];
        }
        if (start >= s.length()) {
            return vector<string> {""};
        }

        vector<string> ans;
        for (int j = start; j < s.length(); ++j) {
            string tmp = s.substr(start, j-start+1);
            if (__words.find(tmp) != __words.end() ) {
                vector<string> str_vec = __dfs(s, j+1);
                for (string str : str_vec) {
                    ans.push_back (tmp + (str.empty() ? "" : " " + str) );
                }
            }
        }

        __m[start] = ans;
        return ans;
    }
};
