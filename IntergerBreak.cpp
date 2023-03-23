class Solution {
public:
    int solve(int n, int *dp){
        //base case
        if(n == 1){
            return dp[1] = 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        //recursive case
        int max_product = 0;
        for(int i = 1; i<n; i++){
            int temp = max(i*(n-i),i*solve(n-i,dp));
            max_product = max(max_product,temp);
        }
        return dp[n] = max_product;
    }
    int integerBreak(int n) {
        int dp[1000];
        memset(dp,-1,sizeof(dp));
        return solve(n,dp);
    }
};