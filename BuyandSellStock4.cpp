#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int memo[1001][2][101];
	int solve(vector<int>& prices,int i,bool buy,int k){
		//base case
		if(i == prices.size()){
			return 0;
		}
		if(memo[i][buy][k] != -1){
			return memo[i][buy][k];
		}
		//recursive case
		//i dont buy or sell the stock
		int ans = solve(prices,i+1,buy,k);
		if(buy and k){
			ans = max(ans, -prices[i]+solve(prices,i+1,false,k));
		}
		else{
			ans = max(ans, prices[i]+solve(prices,i+1,true,k-1));
		}
		return memo[i][buy][k] =  ans;
	}
    int maxProfit(int k, vector<int>& prices) {
    	memset(memo,-1,sizeof(memo));
        return solve(prices,0,true,k);
    }
};

int main(){
	Solution H;
	vector<int> prices = {3, 2, 6, 5, 0, 3};
	cout<<H.maxProfit(2,prices);
	return 0;
}