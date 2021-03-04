class Solution {
public:
	int kthGrammar(int N, int K) {
		if (N == 1)
			return 0;
		if (N == 2)
			return K - 1;

		int pre_len = 1 << (N - 2);
		if (K <= pre_len)
			return kthGrammar(N - 1, K);
		else
			return 1 - kthGrammar(N - 1, K-pre_len);
	}
};