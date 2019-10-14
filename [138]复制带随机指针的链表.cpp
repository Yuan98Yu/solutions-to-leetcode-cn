#include <map>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		map<Node*, Node*> visited;
		return backtrack(head, visited);
	}
	Node* backtrack(Node* head, map<Node*, Node*>& visited) {
		if (head == nullptr)
			return nullptr;
		if (visited.find(head) != visited.end())
			return visited[head];

		Node* new_head = new Node(head->val, nullptr, nullptr);
		visited[head] = new_head;
		new_head->next = backtrack(head->next, visited);
		new_head->random = backtrack(head->random, visited);

		return new_head;
	}
};