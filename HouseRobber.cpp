#include<iostream>
using namespace std;

int solve(int *arr, int i,int n){
	//base case
	if(i>=n){
		return 0;
	}
	//recursive case
	int op1,op2 = INT_MIN;
	op1 = arr[i]+solve(arr,i+2,n);
	op2 = 0+solve(arr,i+1,n);

	return max(op1,op2);
}

int bottomUp(int *arr,int n){

	int dp[n+1];
	dp[0] = 0;
	//corner cases
	if(n == 1){
		return max(arr[0],0);
	}
	else if(n == 2){
		return max(0,max(arr[0],arr[1]));
	}

	dp[0] = max(arr[0],0);
	dp[1] = max(0,max(arr[0],arr[1]));

	for(int i = 2; i<n; i++){
		int inc = arr[i]+dp[i-2];
		int exc = 0+dp[i-1];

		dp[i] = max(inc,exc);
	}
	return dp[n-1];
}

int main(){

	int arr[] = {1,2,3,1};
	int n = sizeof(arr)/sizeof(int);
	cout<<solve(arr,0,n);
	cout<<bottomUp(arr,n);
	return 0;
}