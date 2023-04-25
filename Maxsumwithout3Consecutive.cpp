//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  int findMaxSum(vector<int>& arr){
      //Code Here
      int n = arr.size();
      if(n == 0){
          return 0;
      }
      else if(n == 1){
          return arr[0];
      }
      else if(n == 2){
          return max(arr[0],arr[1]);
      }
      
      int dp[100005];
      dp[0] = arr[0];
      dp[1] = arr[0]+arr[1];
      dp[2] = max({arr[2]+arr[1],dp[1],arr[0]+arr[2]});
      
      for(int i = 3; i<n; i++){
          dp[i] = max(dp[i-1],max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]));
      }
      return dp[n-1];
  }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
