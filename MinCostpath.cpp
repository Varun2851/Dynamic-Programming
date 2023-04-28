class Solution {
public:
    vector<vector<int>>memo;
    int solve(vector<vector<int>>& grid,int n, int m,int i, int j){
        //base case
        if(i<0 || i>=n || j<0 || j>=m){
            return INT_MAX;
        }
        if(i == n-1 and j == m-1){
            return  memo[i][j] = grid[i][j];
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        //recursive case
        int sum = 0;
        int right = solve(grid,n,m,i+1,j);
        int down = solve(grid,n,m,i,j+1);

        sum = grid[i][j]+min(right,down);
        return  memo[i][j] = sum;
    }


    int bottomUp(vector<vector<int>>& grid,int n, int m){
        memo[0][0] = grid[0][0];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 and j == 0){
                    memo[i][j] =grid[i][j]; 
                }
                else if(i == 0){
                    memo[i][j] = grid[i][j]+memo[i][j-1];
                }
                else if(j == 0){
                    memo[i][j] = grid[i][j]+memo[i-1][j];
                }
                else{
                    memo[i][j] = grid[i][j]+min(memo[i-1][j],memo[i][j-1]);
                }
            }
        }
        return memo[n-1][m-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //memo.resize(n+1,vector<int>(m+1,-1));
        //return solve(grid,n,m,0,0);
        memo.resize(n+1,vector<int>(m+1,0));
        return bottomUp(grid,n,m);
    }
};