class Solution {
public:
    int solve(int target,vector<int>&dp,vector<int>& nums){

        if (target == 0) return 1;

        if (target < 0) return 0;

        if (dp[target] != -1) return dp[target];

        int ways = 0;

        for (int num : nums){
            ways += solve(target - num,dp,nums);
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {

        vector<int>dp(10001,-1);
        
       return solve(target,dp,nums);
    }
};