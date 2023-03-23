#include<iostream>
using namespace std;
int dp[100000];
int NStairs(int n, int k){
	//base case
	if(n == 0){
		return 1;
	}

	if(n<0){
		return 0;
	}

	//recursive case
	int ans = 0;
	for(int i = 1; i<=k; i++){
		ans += NStairs(n-i,k);
	}
	return ans;
}

int topdown(int n , int k){
	//base case
	if(n==0){
		return dp[n] = 1;
	}
	if(n<0){
		return 0;
	}

	if(dp[n] != -1){
		return dp[n];
	}
	//recursive case
	int ans = 0;
	for(int i =  1; i<=k; i++){
		ans += NStairs(n-i,k);
	}

	return dp[n] = ans;
}

int bottomUp(int n, int k){
	int dp[1000];
	dp[0] = 1;

	for(int i = 1; i<=n; i++){
		int ans = 0;
		for(int j = 1; j<=k; j++){
			if(i>=j){
				ans += dp[i-j];
			}
		}
		dp[i] = ans;
	}
	return dp[n];
}

int main(){
	int n,k;
	cin>>n>>k;

	cout<<NStairs(n,k)<<endl;
	cout<<topdown(n,k)<<endl;
	cout<<bottomUp(n,k)<<endl;
	return 0;
}