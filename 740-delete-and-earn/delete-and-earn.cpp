class Solution {
public:

    int solve(int* freq, int n, int *dp){

        if (n <= 0) return 0;

        if (dp[n] != -1) return dp[n];

        int op1 = freq[n-1] + solve(freq,n-2,dp);
        int op2 = solve(freq,n-1,dp);

        return dp[n] = max(op1,op2);
    }

    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();

        int freq[10005];
        memset(freq,0,sizeof(freq));

        for (int i = 0; i < n; i++){
            freq[nums[i]] += nums[i];
        }

        int dp[10005];
        memset(dp,-1,sizeof(dp));


        int mx = *max_element(nums.begin(), nums.end());

        return solve(freq,mx + 1,dp);
    }
};