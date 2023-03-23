//Piyush and nimit are playing a game. They are given n coin with values X1,X2....Xn where n is always even. they take alternate turn
//.In each turn a player picks either the firs coin or the last coin from row and remove it from the row .
//The values  of coin is recieved by the player .Determine the maximum values that piyush can earn and win the game if he moves the first
//Both the player play the game optimially

#include<iostream>
using namespace std;

int solve(int *coins,int n,int i, int j){
	//base case
	if(i>j){
		return 0;
	}

	//recursive case
	int op1 = coins[i]+min(solve(coins,n,i+2,j),solve(coins,n,i,j-1));
	int op2 = coins[j]+min(solve(coins,n,i,j-2),solve(coins,n,i+1,j));

	return max(op1,op2);
}

int main(){

	int coins[] = {1,2,3,4};
	int n = sizeof(coins)/sizeof(int);
	cout<<solve(coins,n,0,n-1);
	return 0;
}