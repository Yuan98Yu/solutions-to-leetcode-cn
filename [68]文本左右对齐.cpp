#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start = 0;
        int cur_len = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (cur_len + words[i].size() + i - start > maxWidth) {
                string tmp = words[start];
                int end = i - 1;
                if (end == start) {
                    tmp.append(maxWidth - cur_len, ' ');
                }
                else {
                    int interval_num = (maxWidth - cur_len) / (end - start);
                    int j = start + 1;
                    for (; j <= start + (maxWidth - cur_len) % (end - start); ++j) {
                        tmp.append(interval_num + 1, ' ');
                        tmp.append(words[j]);
                    }
                    for (; j <= end; ++j) {
                        tmp.append(interval_num, ' ');
                        tmp.append(words[j]);
                    }
                }
                ans.push_back(tmp);
                start = i;
                cur_len = words[i].size();
            }
            else {
                cur_len += words[i].size();
            }
        }
        string tmp = words[start];
        for (int i = start + 1; i < words.size(); ++i) {
            tmp.append(" ");
            tmp.append(words[i]);
        }
        tmp.append(maxWidth-cur_len-words.size()+start+1, ' ');
        ans.push_back(tmp);

        return ans;
    }
};
