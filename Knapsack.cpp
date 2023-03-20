#include<bits/stdc++.h>
using namespace std;

int Knapsack(int *prices,int *weight, int n,int capacity,int dp[100][100]){
	//base case
	if(n==0 or capacity == 0){
		return dp[n][capacity] = 0;
	}

	//recursive case
	int op1 ,op2 = INT_MIN;
	//1.item ko rob kruga
	if(dp[n][capacity] != -1){
		return dp[n][capacity];
	}
	if(capacity >= weight[n-1]){
		op1 = prices[n-1]+Knapsack(prices,weight,n-1,capacity-weight[n-1],dp); 
	}

	//2.item ko rob nh kruga
	op2 = 0+Knapsack(prices,weight,n-1,capacity,dp);

	return dp[n][capacity] =  max(op1,op2);
}

int bottomup(int *prices,int *weight,int N,int capacity){
	vector<vector<int> > dp(N + 1, vector<int>(capacity + 1, 0));
	int op1 = INT_MIN,op2 = INT_MIN;

	for(int n = 1; n<=N; n++){
		for(int c = 1; c<=capacity; c++){
			if(weight[n-1] <= c){
				op1 = prices[n-1]+dp[n-1][c-weight[n-1]];
			}
			op2 = 0+dp[n-1][c];
			dp[n][c] = max(op1,op2);
		}
	}
	return dp[N][capacity];
}

int main(){
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	int prices[] = {2,1,4,4};
	int weight[] = {1,2,3,2};
	int capacity = 2;

	int n = sizeof(prices)/sizeof(int);
	cout<<Knapsack(prices,weight,n,capacity,dp);
	cout<<endl;
	cout<<bottomup(prices,weight,n,capacity);

	return 0;
}