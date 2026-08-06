class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        // Base case: length = 1
        for (int j = 0; j < 5; j++)
            dp[1][j] = 5 - j;

        for (int len = 2; len <= n; len++) {
            dp[len][4] = 1;
            for (int j = 3; j >= 0; j--) {
                dp[len][j] = dp[len - 1][j] + dp[len][j + 1];
            }
        }

        return dp[n][0];
    }
};