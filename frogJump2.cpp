#include<bits/stdc++.h>
using namespace std;

int solve(int *arr,int n,int k,int  i){
	//base case
	if(i == 0){
		return 0;
	}
	//recursive case
	int ans = INT_MAX;
	for(int kk = 1; kk<=k; kk++){
		if(i>=kk){
			ans = min(ans,solve(arr,n,k,i-kk)+abs(arr[i]-arr[i-kk]));
		}
	}
	return ans;
}

int bottomUp(int *arr,int n,int k){
	int dp[n+1];
	dp[0] = 0;
	dp[1] = dp[0]+abs(arr[1]-arr[0]);

	for(int i = 2; i<n; i++){
		dp[i] = INT_MAX;
		for(int kk = 1; kk<=k; kk++){
			if(i>=kk){
				dp[i] = min(dp[i],dp[i-kk]+abs(arr[i]-arr[i-kk]));
			}
		}
	}
	return dp[n-1];
}

int main(){
	int n = 3;
	int k = 1;
	int arr[] = {10, 20, 10};
	cout<<solve(arr,n,k,n-1);
	cout<<endl;
	cout<<bottomUp(arr,n,k);
	return 0;
} 