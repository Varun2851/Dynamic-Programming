#include<iostream>
using namespace std;

int main(){
	int a[] = {10,9,3,5,4,11,7,8};
	int n = sizeof(a)/sizeof(int);

	int dp[1000];
	for(int i = 0; i<n; i++){
		dp[i] = 1;
	}

	for(int i = 1; i<n; i++){
		for(int j = i-1; j>=0; j--){
			if(a[i]>a[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	// int ans = 1;
	// for(int i= 1; i<n; i++){
	// 	ans = max(ans,dp[i]);
	// }

	int ans = 1;
	int i = 0;
	for (int j = 0 ; j < n ; j++) {
		if (ans < dp[j]) {
			ans = dp[j];
			i = j;
		}
	}


	// Printing the LIS
	vector<int> v;
	v.push_back(a[i]);
	int len = ans;
	len--;
	for (int j = i - 1; j >= 0 ; j--) {
		if (dp[j] == len and v[v.size() - 1] > a[j]) {
			v.push_back(a[j]);
			len--;
			if (len == 0) {
				break;
			}
		}
	}

	for (int i = v.size() - 1 ; i >= 0 ; i--) {
		cout << v[i] << " ";
	}
	cout << endl;



	cout<<ans<<endl;

	return 0;
}