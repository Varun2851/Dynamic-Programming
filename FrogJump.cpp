#include<iostream>
using namespace std;
int dp[10005];
int solve(int *arr,int i){
	//base case
	if(i == 0){
		return dp[i] = 0;
	}
	//recursive case
	if(dp[i] != -1){
		return dp[i];
	}
	int op1,op2 = INT_MAX;
	op1 = solve(arr,i-1)+abs(arr[i]-arr[i-1]);
	if(i-2>=0){
		op2 = solve(arr,i-2)+abs(arr[i]-arr[i-2]);
	}
	return  dp[i] = min(op1,op2);
}

int bottomUp(int *arr,int n){
	int dp[n];
	dp[0] = 0;
	dp[1] = dp[0]+abs(arr[1]-arr[0]);

	for(int i = 2; i<n; i++){
		dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
	}
	
	return dp[n-1];
}

int main(){
	int arr[] = {10,50,40,20};
	int n = 4;
	memset(dp,-1,sizeof(dp));
	cout<<bottomUp(arr,n);
	return 0;
}