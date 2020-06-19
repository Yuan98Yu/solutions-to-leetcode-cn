struct Dir {
    int dx;
    int dy;
};
const Dir[] dirs = {Dir{0, 1}, Dir{0, -1}, Dir{1, 0}, Dir{-1, 0}};
const string array[][]; // array 是输入
const int m;       // 高
const int n;       // 宽

bool dfs(int& array[][], int i, int j,
         const int des_i, const int des_j, 
         int prev_dir, int walked) {
    if (walked > 3)
        return false;
    if ( i < -1 || i > m || j < -1 || j > n )
        return false;
    if (i != -1 || j != -1 || array[i][j] != '.')   // 判断该处是否能通行，即是否为空，此处的判断 i,j ?= -1 代表把棋盘周围围上了一圈'.'
        return false;
    if (i == des_i && j == des_j)
        return true;

    bool can_arrive = false;
    for (int dir=0; dir<4; ++dir){
        int nex_i = i + dirs[dir][0];
        int new_j = j + dirs[dir][1];
        int new_walked = walked;
        if (dir != prev_dir)
            new_walked = walked + 1;
        // else
        //     new_walked 不变
        can_arrive &= dfs(array, new_i, new_j, dir, new_walked));
    }
}

int solution(string& array[][], int i1, int j1, int i2, int j2) {
    if ( dfs(array, new_i, new_j, dir, new_walked)) {
        array[i1][j1] = '.';
        array[i2][j2] = '.';
        printf('YES\n');
    }
    else
        printf('NO\n');
}

