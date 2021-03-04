#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

/* 超时 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        map<string, set<string> > comboDict;
        map<string, set<string> > graph;
        map<string, bool> visited;
        queue<string> q;
        q.push(beginWord);
        int word_length = beginWord.length();
        int path_length = 0;

        for (string word : wordList) {
            visited[word] = false;
            for (int i = 0 ; i < word_length; ++i) {
                string newWord = word.substr(0, i) + '*' + word.substr(i + 1, word_length);
                comboDict[newWord].insert(word);
            }
        }
        visited[beginWord] = true;
        
        bool found_end = false;
        while (!q.empty() && !found_end) {
            int q_size = q.size();
            ++path_length;
            for (int i = 0; i < q_size; ++i) {
                string word = q.front(); q.pop();
                for (int j = 0; j < word_length; ++j) {
                    string newWord = word.substr(0, j) + '*' + word.substr(j + 1, word_length);
                    for (string str : comboDict[newWord]) {
                        graph[word].insert(str);
                        if (str == endWord){
                            found_end = true;
                        }
                        if (!visited[str]) {
                            visited[str] = true;
                            q.push(str);
                        }
                    }
                }
            }
        }
        
        vector<string> path;
        path.push_back(beginWord);
        dfs (graph, beginWord, endWord, path, ans, path_length);
        return ans;
    }

private:
    void dfs(map<string, set<string> > &graph, const string &beginWord, const string &endWord, vector<string>& path, vector<vector<string> > &ans, int rmlen){
		if (beginWord == endWord) {
			ans.push_back(path);
			return;
		}
        if (rmlen <= 0)
            return;
		for (const string &word : graph[beginWord]){
            path.push_back(word);
            dfs(graph, word, endWord, path, ans, --rmlen);
            path.pop_back();
        }
	}
};
