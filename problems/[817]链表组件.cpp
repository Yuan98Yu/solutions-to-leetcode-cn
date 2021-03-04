#include <vector>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		set<int> s;
		for (int num : G)
			s.insert(num);
		bool flag = false;
		int count = 0;
		for (ListNode* p = head; p; p = p->next) {
			if (s.find(p->val) != s.end()) {
				if (flag == false)
					++count;
				flag = true;
			}
			else flag = false;
		}
		return count;
	}
};