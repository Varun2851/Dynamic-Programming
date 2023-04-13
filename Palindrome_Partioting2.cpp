#include<iostream>
using namespace std;

bool isPalindrome(string s){
	int left = 0;
	int right = s.size()-1;

	while(left<right){
		if(s[left] != s[right]){
			return false;
		}
		left++;
		right--;
	}
	return true;
}

int solve(string s,int n){
	//base case
	if(s.empty()){
		return 0;
	}

	if(isPalindrome(s)){ // this base case is necessary because may be the given string is already palindrome
		return 0;
	}
	int minCuts = INT_MAX;
	//recursive case
	for(int i = 1; i<n; i++){
		string left = s.substr(0,i);
		string right = s.substr(i+1);

		if(isPalindrome(left)){
			minCuts = min(minCuts,1+solve(right,n));
		}
	}
	return minCuts;
}

int main(){
	string s = "aab";
	int n = s.size();
	cout<<solve(s,n);
	return 0;
}