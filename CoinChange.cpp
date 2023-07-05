
#include<bits/stdc++.h>
using namespace std;

//Simple recursion
int ExchangeCoins(int *coins,int n,int amount){
	//base case
	if(amount == 0){
		return 0;
	}
	int ans = INT_MAX;
	for(int i= 0; i<n; i++){
		if(amount-coins[i] >= 0){
			int ca = ExchangeCoins(coins,n,amount-coins[i]);

			if(ca != INT_MAX){
				ans = min(ans,ca+1);
			}
		}
	}
	return ans;
}

//Top down Dp

int topDown(int*coins,int n,int amount,int *dp){
	//base case
	if(amount == 0){
		return dp[amount] = 0;
	}

	if(dp[amount] != -1){
		return dp[amount];
	}

	//recursive case
	int ans = INT_MAX;
	for(int i = 0; i<n; i++){
		if(amount-coins[i]>=0){
			int ca = topDown(coins,n,amount-coins[i],dp);
			if(ca != INT_MAX){
				ans = min(ans,ca+1);
			}
		}
	}
	return dp[amount] = ans;
}

//Bottom up

int BottomUp(int *coins,int n,int amount){
	//this is itrative approach
	vector<int>dp(amount+1,INT_MAX);
	dp[0] = 0;

	for(int i = 1; i<=amount; i++){
		for(int j = 0; j<n; j++){ //this loop runs on coin array , one by one we will check which coin should i remove 
			if(i-coins[j] >= 0){
				dp[i] = min(1+dp[i-coins[j]],dp[i]);
			}

		}
	}
	return dp[amount];
}

int main(){

	// int dp[100000];
	// memset(dp,-1,sizeof(dp));
	int coins[] = {1,7,10};
	int n = sizeof(coins)/sizeof(int);
	int amount = 14;

	cout<<BottomUp(coins,n,amount);

	return 0;
}
