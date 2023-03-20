#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll *weight;
ll*prices;
ll dp[101][100001];
ll N,capacity;

int knapsack(int max_profit){
	for(ll n = 0; n<=N; n++){
		for(ll profit = 0; profit<=max_profit; profit++){
			if(n == 0 and profit == 0){
				dp[n][profit] = 0;
			}
			else if(n == 0){
				dp[n][profit] = INT_MAX;
			}
			else if(prices[n-1] <= profit){
				//in this case we can only rob the item
				ll op1 = weight[n-1] +dp[n-1][profit-prices[n-1]];
				ll op2 = dp[n-1][profit];
				dp[n][profit] = min(op1,op2);
			}
			else{
				dp[n][profit] = dp[n-1][profit];
 			}
		}
	}

	ll ans = 0;

	for(ll profit = 0; profit<=max_profit; profit++){
		if(dp[N][profit] <= capacity){
			ans = profit;
		}
	}
	return ans;
}

int main(){
	cin>>N>>capacity;
	 weight = new ll [N+1];
	 prices = new ll [N+1];

	ll max_profit = 0;

	for(int i =  0; i<N; i++){
		cin>>weight[i]>>prices[i];

		max_profit += prices[i];
	}
	cout<<knapsack(max_profit);
	return 0;
}