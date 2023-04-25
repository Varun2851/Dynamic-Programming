//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;


class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
   int lcs(int x, int y, string s1, string s2)
{
    int dp[2][max(x,y)+1];
    memset(dp, 0, sizeof(dp)); // Initialize dp array with 0
    
    for(int i =1; i<=x; i++){
        for(int j = 1; j<=y; j++){
            if(s1[i-1] != s2[j-1]){
                dp[i%2][j] = max(dp[(i-1)%2][j],dp[i%2][j-1]);
            }
            else{
                dp[i%2][j] = 1+dp[(i-1)%2][j-1];
            }
        }
    }
    return dp[x%2][y];
}
};


int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          
        string s1,s2;
        cin>>s1>>s2;
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}