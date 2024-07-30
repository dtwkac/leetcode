class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        bool flag = true;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                flag = false;
            }
            dp[i][0] = flag ? 1 : 0;
        }
        flag = true;
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                flag = false;
            }
            dp[0][j] = flag ? 1 : 0;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] =
                    obstacleGrid[i][j] == 1 ? 0 : (dp[i - 1][j] + dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
