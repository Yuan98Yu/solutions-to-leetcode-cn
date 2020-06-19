struct Dir {
    int dx;
    int dy;
};
const Dir[] dirs = {Dir{0, 1}, Dir{0, -1}, Dir{1, 0}, Dir{-1, 0}};
const int INT_MAX = 999999;

int dfs(const int& array[][], int i, int j, int& memo[][], map<int, int> d) {
    if (memo[i][j] != -1)
        return memo[i][j];
    
    int length = INT_MAX;
    for (int i=0; i<4; ++i){
        int nex_i = i + dirs[i][0];
        int new_j = j + dirs[i][1];
        length = min(length, 1+dfs(array, new_i, new_j, memo, d));
    }
    if (array[i][j] > 0){
        int nex_i = d.get(...);
        int new_j = d.get(...);
        length = min(length, 1+dfs(array, new_i, new_j, memo, d))
    }

    memo[i][j] = length;
    return length;
}

int solution(int array[][], m, n){
    int memo[m][n];
    map<int, int> d = map<int, int> ();
    int start_i;
    int start_j;
    for (i=0; i<m; ++i)
        for (j=0; j<n; ++j) {
            if (array[i][j] == -3)
                memo[i][j] = 0;
            else if (array[i][j] == -1) {
                memo[i][j] = -1;
                start_i = i;
                start_j = j;
            }
            else {
                memo[i][j] = -1;
                d.put(...);
                d.put(...);
            }
        }
            
    return dfs(array, start_i, start_j, memo);
}