#include<bits/stdc++.h>
using namespace std;
int dp[6];
int solve(int *arr,int i){
	//base case
	if(i<3){
		return dp[i] = arr[i];
	}
	//recursive case
	if(dp[i] != -1){
		return dp[i];
	}
	int op1,op2,op3 = INT_MAX;
	if(i-1>=0){
		op1 = arr[i]+solve(arr,i-1);
	}
	if(i-2>=0){
		op2 = arr[i]+solve(arr,i-2);
	}
	if(i-3>=0){
		op3 = arr[i]+solve(arr,i-3);
	}
	return dp[i] = min(op1,min(op2,op3));

}

void bottomUp(int *arr,int n){
	vector<int>dp(n+1,-1);
	dp[0] = arr[0];
	dp[1] = arr[1];
	dp[2] = arr[2];
	int op1,op2,op3 = INT_MAX;
	for(int i = 3; i<n; i++){
		if(i-1>=0){
			op1 = arr[i]+dp[i-1];
		}
		if(i-2>=0){
			op2 = arr[i]+dp[i-2];
		}
		if(i-3>=0){
			op3 = arr[i]+dp[i-3];
		}
		dp[i] = min(op1,min(op2,op3));
	}
}

int main(){
	int arr[] = {2,2,3,2,3};
	int n = 5;
	memset(dp,-1,sizeof(dp));
	// solve(arr,n-1);
	//cout<<min(dp[n-1],min(dp[n-2],dp[n-3]));
	bottomUp(arr,n);
	cout<<min(dp[n-1],min(dp[n-2],dp[n-3]));
	return 0;
}