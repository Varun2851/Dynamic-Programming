#include<bits/stdc++.h>
using namespace std;

int solve(int n){
	//base case
	if(n<=2){
		return 1;
	}
	//recursive case
	return solve(n-1)+solve(n-2);
}

int bottomUp(int n){
	vector<int>dp(n+1);
	dp[1] = dp[2] = 1;

	for(int i = 3; i<=n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main(){
	int n = 10;
	cout<<solve(10);
	cout<<bottomUp(n);
	return 0;
}