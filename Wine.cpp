#include<bits/stdc++.h>
using namespace std;

int solve(int *wine,int n,int i,int j,int day){
	//base case
	if(i>j){
		return 0;
	}
	int ans = INT_MIN;
	//recursive case , no need to apply while loop because i and j are incremented by recursion itself
	
	int op1 = wine[i]*day+solve(wine,n,i+1,j,day+1);
	int op2 = wine[j]*day+solve(wine,n,i,j-1,day+1);

	ans = max(op1,op2);

	return ans;
}

//Top-Down

int topdown(int *wine,int n,int i,int j,int day,int dp[][100]){
	//base case
	if(i>j){
		return dp[i][j] = 0;
	}
	//check before calculating
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int ans = INT_MIN;
	//recursive case
	int op1 = wine[i]*day+topdown(wine,n,i+1,j,day+1,dp);
	int op2 = wine[j]*day+topdown(wine,n,i,j-1,day+1,dp);

	ans = max(op1,op2);

	return dp[i][j] =ans;
}

//bottom-up

int bottomUp(int *wine,int n){
	int dp[100][100] = {0};
	//first fill all the diagonal
	for(int i = 0; i<n; i++){
		dp[i][i] = wine[i]*n;
	}
	//now fill the matrix from down to up
	for(int i = n-2; i>=0; i--){
		for(int j =  0; j<n; j++){
			//we have to fill only those cells which have j > i
			if(j>i){
				int day = n-(j-i);
				int op1 = wine[i]*day+dp[i+1][j];
				int op2 = wine[j]*day+dp[i][j-1];

				dp[i][j] = max(op1,op2);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	int wine[] = {2,3,5,1,4};
	int n = 5;
	int day = 1;
	cout<<bottomUp(wine,n);
	return 0;
}