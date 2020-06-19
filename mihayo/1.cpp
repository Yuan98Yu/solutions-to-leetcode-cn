#include <vector>
#include <map>
using namespace std;

class Solution:
public:
    map< int, vector<int> > B_memo = map< int, vector<int> > ();


    int maxUncrossedLines(vector<int>& A,vector<int>& B) {
        
    }
        
        for i in range(len(B)):
            records = B_memo.get(B[i], [])
            records.append(i)
            B_memo[B[i]] = records

        def dp(A_idx, max_B_idx):
            if A_idx == len(A):
                return 0

            val = A[A_idx]
            records = B_memo.get(val, None)
            if records is None:
                return dp(A_idx+1, max_B_idx)
            else:
                i = 0
                while records[i] <= max_B_idx:
                    i += 1
                if i == len(records):
                    return dp(A_idx+1, max_B_idx)
                else:
                    tmp1 = dp(A_idx+1, max_B_idx)
                    tmp2 = 1+dp(A_idx+1, records[i])
                    return max(tmp1, tmp2)
        
        return dp(0, -1)
            

