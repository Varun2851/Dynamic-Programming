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

int main(){
	int arr[] = {10,30,40,20};
	int n = 4;
	memset(dp,-1,sizeof(dp));
	cout<<solve(arr,n-1);
	return 0;
}