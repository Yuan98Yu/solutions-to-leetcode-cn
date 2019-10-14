#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "[120]三角形最小路径和.cpp"
using namespace std;

//void test_8() {
//	Solution solution;
//	printf("%d", solution.myAtoi(" -91238719211"));
//}
//void test_10() {
//	Solution solution;
//	cout << solution.isMatch("ab", "..*");
//}
//void test_12() {
//	Solution solution;
//	cout << solution.intToRoman(1994);
//}
//void test_13() {
//	Solution solution;
//	cout << solution.romanToInt2("IXIV");
//}
//void test_14() {
//	Solution solution;
//	vector<string> strs = {"apple","apb"};
//	cout << solution.longestCommonPrefix(strs);
//}
//void test_17() {
//	Solution solution;
//	vector<string> ans = solution.rec_comb("23");
//	for (auto str : ans) {
//		cout << str << " ";
//	}
//}
//void test_18() {
//	Solution solution;
//	vector<int> nums = { 1,0,-1,0,-2,2 };
//	int target = 0;
//	vector<vector<int>> ans = solution.fourSum(nums, target);
//	for (auto per_ans : ans) {
//		cout << "per_ans: ";
//		for (int num : per_ans)
//			cout << num << " ";
//		cout << endl;
//	}
//}
//void test_28() {
//	Solution solution;
//	cout<< solution.
//}
//void test_29() {
//	Solution solution;
//	cout << solution.strStr4("vffheaalaloa", "aalaloa");
//}
//void test_32() {
//	Solution solution;
//	cout << solution.longestValidParentheses("(())())");
//}
//void test_33() {
//	Solution solution;
//	
//	cout << solution.search(vector<int> {4, 5, 6, 7, 0, 1, 2}, 0);
//void test_42() {
//	Solution solution;
//	vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };
//	int ans = solution.trap(nums);
//	cout << ans << endl;
//}
//void test_44() {
//	Solution solution;
//	cout<<solution.isMatch("cb", "?a");
//}
//void test_45() {
//	Solution solution;
//	vector<int> input = { 2, 3, 1, 1, 4 };
//	solution.jump(input);
//}
//void test_47() {
//	Solution solution;
//	vector<int> nums = { 2, 2, 1, 1 };
//	vector<vector<int>> ans = solution.permuteUnique(nums);
//	for (auto per : ans) {
//		cout << "[";
//		for (auto num : per)
//			cout << num << ",";
//		cout << "]" << endl;
//	}
//}
//void test_60() {
//	Solution solution;
//	auto ans = solution.getPermutation(3,35);
//	cout << ans;
//}
//void test_61() {
//	Solution solution;
//	ListNode* head = new ListNode(0);
//	head->next = new ListNode(1);
//	head->next->next = new ListNode(2);
//	solution.rotateRight(head, 4);
//}
//void test_62() {
//	Solution solution;
//	cout << solution.uniquePaths(4, 3);
//}
void test_120() {
	Solution solution;
	vector<vector<int>> input{ {-1},{2,3},{1,-1,-3} };
	solution.minimumTotal(input);
}
//void test_147() {
//	Solution solution;
//	ListNode* head = new ListNode(4);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(1);
//	head->next->next->next = new ListNode(3);
//
//	solution.insertionSortList(head);
//}
//void test_222() {
//	Solution solution;
//	TreeNode* root = new TreeNode(1);
//	TreeNode* t2 = new TreeNode(2);
//	TreeNode* t3 = new TreeNode(3);
//	TreeNode* t4 = new TreeNode(4);
//	TreeNode* t5 = new TreeNode(5);
//	TreeNode* t6 = new TreeNode(6);
//	root->left = t2;
//	root->right = t3;
//	t2->left = t4;
//	t2->right = t5;
//	t3->left = t6;
//	cout << solution.countNodes(root);
//}
//void test_234() {
//	ListNode* head = new ListNode(0);
//	ListNode* next = new ListNode(0);
//	head->next = next;
//	Solution solution;
//	cout<<solution.isPalindrome(head);
//}
//ifstream f_in;
//char ch[60];
//f_in.open("test.cpp");
//f_in.getline(ch, 256);
//for (int i = 0; ch[i] != '\0'; ++i) {
//	if (ch[i] == ' ')
//		continue;
//	nums1.push_back(ch[i] - '0');
//}
//f_in.getline(ch, 256);
//for (int i = 0; ch[i] != '\0'; ++i) {
//	if (ch[i] == ' ')
//		continue;
//	nums2.push_back(ch[i] - '0');
//}
//f_in >> k;
//void test_321() {
//	Solution solution;
//	vector<int> nums1 = { 0 };
//	vector<int> nums2 = { 0, 6, 5, 7, 6, 2};
//	int k = 7;
//	vector<int> ans;
//	ans = solution.maxNumber(nums1, nums2, k);
//	for (int num : ans)
//		cout << num << " ";
//}
int main() {
	test_120();
}