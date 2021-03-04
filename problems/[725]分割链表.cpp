#include <cstdlib>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> ans(k, NULL);
		int len = 0;
		for (ListNode* p = root; p; p = p->next)
			++len;
		int a = len / k;
		int b = len % k;
		ListNode* p = root;
		int i = 0;
		for (; b > 0; --b) {
			ans[i++] = p;
			for (int count = a; count > 0; --count, p = p->next);
			ListNode* tmp = p;
			p = p->next;
			tmp->next = NULL;
		}
		if (a > 0) {
			for (; i < k - 1; ++i) {
				ans[i] = p;
				for (int count = a; count > 1; --count, p = p->next);
				ListNode* tmp = p;
				p = p->next;
				tmp->next = NULL;
			}
			ans[i] = p;
		}
		return ans;
	}
};