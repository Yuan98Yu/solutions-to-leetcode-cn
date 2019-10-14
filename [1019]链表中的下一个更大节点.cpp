#include <stack>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> ans;
		stack<pair<int, int>> s;
		int count = 0;
		for (ListNode* p = head; p != nullptr; p = p->next) {
			ans.push_back(0);
			while (!s.empty() && p->val > s.top().first) {
				ans[s.top().second] = p->val;
				s.pop();
			}
			s.push(make_pair(p->val, count++));
		}
		return ans;
	}
};