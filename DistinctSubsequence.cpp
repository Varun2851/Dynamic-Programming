// Given two strings s and t, return the number of distinct 
// subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.
// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

#include<iostream>
using namespace std;

int dp[100][100];

int solve(string s, string t,int i , int j){
    //base case
    if(i == -1 and j == -1){
        return 1; //index are not negtaive so we cant store it in our dp table , thats why here we are not writing dp[i][j] = 1
    }
    if(j == -1){
        return 1;
    }
    if(i == -1){
        return 0; 
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //recursive case
    if(s[i] == t[j]){
        return dp[i][j] = solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
    }
    else{
        return  dp[i][j] =  solve(s,t,i-1,j);
    }
}

int bottomUp()

int main(){
    string s = "babgbag";
    string t = "bag";
    int n = s.size();
    int m = t.size();
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,t,n-1,m-1);
    return 0;
}