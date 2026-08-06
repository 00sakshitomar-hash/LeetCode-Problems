class Solution {
public:
    int solve(int dice, int k, int target,vector<vector<int>>&dp){

        // base case
        // if dice = 0,target = 0
        if (dice == 0 && target == 0) return 1;

        if (dice == 0 || target < 0) return 0;

        if (dp[dice][target] != -1) return dp[dice][target];

        int ways = 0;
        const int MOD = 1e9 + 7;
        for (int face = 1; face <= k; face++){
            ways = (ways + solve(dice - 1, k, target - face, dp)) % MOD;
        }

        return dp[dice][target] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(n,k,target,dp);
    }
};