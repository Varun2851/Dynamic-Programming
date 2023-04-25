// The problem statement is as follows: There are n members in a gang, 
// and they want to make a profit by committing various crimes. 
// The gang has a list of crimes to commit, where each crime is characterized by two integers: 
// the amount of profit it generates, and the amount of group members required to commit it. 
// The gang has a minimum profit goal, minProfit, which they want to achieve. 
// Each member of the gang can only commit one crime at a time.

// The goal is to find the total number of different schemes 
// the gang can form to achieve at least minProfit, given that there are n members 
// and a list of crimes with their corresponding profits and group member requirements.

// Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
// Output: 7
// Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
// There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).


class Solution {
public:
    int mod=1e9+7;
    int find(int i,int p,int minProfit,vector<int>& group,vector<int>& profit,int n,int& size,vector<vector<vector<int>>>& dp){
        if(i==size){
            if(p>=minProfit){
                return 1;
            }
            return 0;
        }
        if(dp[i][n][p]!=-1){
            return dp[i][n][p];
        }
        int take=0,not_take=0;
        if(group[i]<=n){
            if(minProfit<=p){ // ye line sirf isliye likha hua h jab n jyada bada hota h tb runtime error aa jata h because baar baar profit cal hota h isliye 
                take=find(i+1,p,minProfit,group,profit,n-group[i],size,dp)%mod;
            }else{
                take=find(i+1,p+profit[i],minProfit,group,profit,n-group[i],size,dp)%mod;
            }
        }
        not_take=find(i+1,p,minProfit,group,profit,n,size,dp)%mod;
        return dp[i][n][p]=(take+not_take)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size=group.size();
        vector<vector<vector<int>>> dp(size,vector<vector<int>>(n+1,vector<int>(201,-1)));
        return find(0,0,minProfit,group,profit,n,size,dp);
    }
};