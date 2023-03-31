#include<bits/stdc++.h>
using namespace std;

int colorfulKnapsack(int *weight,int *color,int n,int m,int capacity){

	//to store all the weight that have ith color
	vector<vector<int>>colorweight(m+1);

	for(int i = 0; i<n; i++){
		colorweight[color[i]].push_back(weight[i]);
	}

	bool dp[m+1][capacity+1];

	//initialize all the values to false
	memset(dp,false,sizeof(dp));

	//we can have 0 weight using 0 color
	dp[0][0] = true;

	//iterate for color from 1 to m
	for(int i = 1; i<=m; i++){
		//to check whether we can use the ith color or not
		bool exists = false;
		for(int j = 0; j<=capacity; j++){
			//traverse through all weight of ith color
			for(auto wt:colorweight[i]){
				if(j-wt>=0){
					dp[i][j] |= dp[i-1][j-wt];
				}
			}

			if(dp[i][j]){
				exists = true;
		    }
		}
	}

	//choose the maximum possible  weight we can achieve using m colors
	for(int i = capacity; i>0; i--){
		if(dp[m][i]){
			return i;
		}
	}
    return -1;
}

int main(){
	int n = 8;
	int m  = 3;
	int capacity = 13;
	int weight[] = {2,3,4,2,4,5,2,3};
	int color[] = {1,1,1,2,2,2,3,3};
	cout<<colorfulKnapsack(weight,color,n,m,capacity);
	return 0;
}