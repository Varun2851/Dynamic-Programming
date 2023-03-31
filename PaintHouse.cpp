#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int cost[3][n];

	for(int i = 0; i<n; i++){
		cin>>cost[0][i]; //taking input for 0th row
	}

	for(int i = 0; i<n; i++){
		cin>>cost[1][i];
	}

	for(int i = 0; i<n; i++){
		cin>>cost[2][i];
	}
	int dp[3][n];

	dp[0][0] = cost[0][0];
	dp[1][0] = cost[1][0];
	dp[2][0] = cost[2][0];

	for(int j = 1; j<n; j++){
		dp[0][j] = dp[1][j] = dp[2][j] = INT_MAX;
		for(int i = 0; i<3; i++){
			for(int k = 0; k<3; k++){
				if(i != k){
					dp[i][j] = min(dp[i][j],dp[k][j-1]+cost[i][j]);
				}
			}
		}
	}

	cout<<min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]));

	return 0;
}

//Space optimised code 

#include<bits/stdc++.h>
using namespace std;

int main()
{
  
    int n;
    cin >> n;
    int cost[3][n];

    for (int i = 0; i < n; i++) {
        cin >> cost[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[1][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[2][i];
    }

    int dp0 = cost[0][0], dp1 = cost[1][0], dp2 = cost[2][0];

    for (int j = 1; j < n; j++) {
        int new_dp0, new_dp1, new_dp2;
        new_dp0 = min(dp1, dp2) + cost[0][j];
        new_dp1 = min(dp0, dp2) + cost[1][j];
        new_dp2 = min(dp0, dp1) + cost[2][j];
        dp0 = new_dp0;
        dp1 = new_dp1;
        dp2 = new_dp2;
    }

    cout << min({dp0, dp1, dp2});

    return 0;
}

//If there are k colors then we can do this

#include<bits/stdc++.h>
using namespace std;

int main()
{
   

    int n, k;
    cin >> n >> k;
    int cost[k][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> cost[j][i];
        }
    }

    int dp[k];
    for (int j = 0; j < k; j++) {
        dp[j] = cost[j][0];
    }

    for (int i = 1; i < n; i++) {
        int new_dp[k];
        for (int j = 0; j < k; j++) {
            new_dp[j] = INT_MAX;
            for (int c = 0; c < k; c++) {
                if (c != j) {
                    new_dp[j] = min(new_dp[j], dp[c] + cost[j][i]);
                }
            }
        }
        for (int j = 0; j < k; j++) {
            dp[j] = new_dp[j];
        }
    }

    cout << *min_element(dp, dp + k);

    return 0;
}

