class Solution {
public:
    int f(vector<int>& coins,int sum,vector<vector<int>> &dp,int ind){

        if(ind == 0){
            if(sum % coins[ind] == 0 ){
                return sum/coins[ind];
            }
            else return 1e9;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int nottake = 0 + f(coins,sum,dp,ind-1);
        int take = 1e9;
        if(coins[ind]<=sum){
            take = 1 + f(coins,sum-coins[ind],dp,ind);
        }
        dp[ind][sum] = min(take,nottake);
        return dp[ind][sum];

    }

    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
       int a =  f(coins,sum,dp,n-1);
       if(a==1e9) return -1;
        return a;
    }
};