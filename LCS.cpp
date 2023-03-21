#include<iostream>
using namespace std;
int dp[100][100];
int LCS(string &s1,string &s2,int i,int j){
	//base case
	if(s1[i] == '\0' or s2[j] == '\0'){
		return 0;
	}

	//recursive case
	if(s1[i] == s2[j]){
		return 1+LCS(s1,s2,i+1,j+1);
	}
	else{
		return max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
	}
}

int topDown(string s1,string s2, int i,int j){
	//base case
	if(s1[i] == '\0' or s2[j] == '\0'){
		return dp[i][j] = 0;
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	//recursive case

	if(s1[i] == s2[j]){
		return dp[i][j] =  1+LCS(s1,s2,i+1,j+1);
	}
	else{
		return dp[i][j] = max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));
	}
}

int bottomup(string s1, string s2){
	int dp[100][100] = {0};
	int n = s1.size();
	int m = s2.size();

	for(int i =  1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(s1[i-1] != s2[j-1]){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
			else{
				dp[i][j] = 1+dp[i-1][j-1];
			}
		}
	}

	for (int i = 0; i <= n ; i++) {
		for (int j = 0; j <= m ; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	//printing the LCS
	//we will try to print the LCS with the help of previous matrix

	char ans[100];

	int i = n;
	int j = m;
	int indx = dp[n][m];
	ans[indx] = '\0';
	indx--;

	while(i>0 and j>0){
		if(s1[i-1] == s2[j-1]){
			ans[indx--] = s1[i-1];
			i--;
			j--;
		}
		else{
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}

	cout<<ans<<endl;

	return dp[n][m];
}

int main(){

	// char s1[100];
	// char s2[100];
	string s1;
	string s2;

	//we can take both of them either string or char array
	//both are perfectly fine

	cin>>s1>>s2;
	memset(dp,-1,sizeof(dp));

	//cout<<LCS(s1,s2,0,0)<<endl;
	cout<<topDown(s1,s2,0,0)<<endl;
	cout<<bottomup(s1,s2)<<endl;

	return 0;
}