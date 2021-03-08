#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, set<string> > comboDict;
        map<string, bool> visited;
        queue<string> q;
        q.push(beginWord);
        int word_length = beginWord.length();
        int ans = 1;

        for (string word : wordList) {
            visited[word] = false;
            for (int i = 0 ; i < word_length; ++i) {
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1, word_length);
                comboDict[newWord].insert(word);
            }
        }
        visited[beginWord] = true;
        
        while (!q.empty()) {
            int q_size = q.size();
            ++ans;
            for (int i = 0; i < q_size; ++i) {
                string word = q.front(); q.pop();
                for (int j = 0; j < word_length; ++j) {
                    string newWord = word.substr(0, j) + '*' + word.substr(j + 1, word_length);
                    for (string str : comboDict[newWord]) {
                        if (str == endWord){
                            return ans;
                        }

                        if (!visited[str]) {
                            visited[str] = true;
                            q.push(str);
                        }
                    }
                }
            }
        }
        return 0;
    }
};