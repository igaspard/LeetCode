class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int grid[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                grid[i][j] = 1;

        for(int i = 0; i < mines.size();i++)
            grid[mines[i][0]][mines[i][1]] = 0;

        int ans = 0;

        for(int y = 0; y < N; y++) {
            for(int x = 0; x < N; x++) {
                int plussign = 0;

                if(grid[y][x]==0)
                    plussign = 0;
                else {
                    int l;
                    for(l = 1; l < N; l++) {
                        int up = y - l;
                        if (up < 0)
                            break;
                        int down = y + l;
                        if (down >= N)
                            break;
                        int left = x - l;
                        if (left < 0)
                            break;
                        int right = x + l;
                        if (right >= N)
                            break;

                        if(!grid[up][x] || !grid[down][x] || !grid[y][left] || !grid[y][right])
                            break;
                    }
                    plussign = l;
                }

                if (plussign > ans)
                    ans = plussign;
            }
        }
        return ans;
    }
};
