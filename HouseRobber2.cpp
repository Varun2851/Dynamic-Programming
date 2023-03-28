#include<iostream>
using namespace std;

int solve(int *nums,int start,int end){
	int n = end-start+1;
	int dp[n+1];

	//corner cases
	if(n == 1){
		return max(0,nums[start]);
	}
	if(n == 2){
		return max(0,max(nums[start],nums[start+1]));
	}
	dp[0] = max(0,nums[start]);
	dp[1] = max(0,max(nums[start],nums[start+1]));

	for(int i = 2; i<n; i++){
		int inc = nums[i+start]+dp[i+2];
		int exc = 0+dp[i+1];

		dp[i] = max(inc,exc);
	}
	return dp[n-1];
}

int main(){
	int nums[] = {2,3,2};
	int n = 3;
	cout<<max(solve(nums,0,n-2),solve(nums,1,n-1));
	return 0;
}