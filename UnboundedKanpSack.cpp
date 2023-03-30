#include<bits/stdc++.h>
using namespace std;

int UnboundedKnapsack(int *prices,int *weight, int n,int capacity,int dp[100][100]){
	//base case
	if(n==0 or capacity == 0){
		return dp[n][capacity] = 0;
	}

	//recursive case
	if(dp[n][capacity] != -1){
		return dp[n][capacity];
	}

	int max_val = INT_MIN;

	// iterate over all items to include them in the knapsack
	for(int i=0; i<n; i++){
		if(capacity >= weight[i]){
			int op1 = prices[i]+UnboundedKnapsack(prices,weight,n,capacity-weight[i],dp); 
			max_val = max(max_val, op1);
		}
	}

	// include no items
	int op2 = 0+UnboundedKnapsack(prices,weight,n-1,capacity,dp);

	return dp[n][capacity] =  max(max_val,op2);
}

int bottomup(int *prices,int *weight,int N,int capacity){
	vector<int> dp(capacity + 1, 0);
	int op1 = INT_MIN;

	for(int c = 1; c<=capacity; c++){
		// iterate over all items to include them in the knapsack
		for(int n = 0; n<N; n++){
			if(weight[n] <= c){
				op1 = prices[n]+dp[c-weight[n]];
				dp[c] = max(dp[c], op1);
			}
		}
	}
	return dp[capacity];
}

int main(){
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	int prices[] = {2,1,4,4};
	int weight[] = {1,2,3,2};
	int capacity = 5;

	int n = sizeof(prices)/sizeof(int);
	cout<<UnboundedKnapsack(prices,weight,n,capacity,dp)<<endl;
	cout<<bottomup(prices,weight,n,capacity)<<endl;

	return 0;
}
