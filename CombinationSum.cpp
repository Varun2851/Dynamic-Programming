class Solution {
public:
    vector<vector<int>ans;
    vector<int>v;
    void solve(vector<int>& candidates,int i,int sum,int target){
        //base case
        if(sum == target){
            ans.push_back(v);
            return;
        }
        if(i>=candidates.size()-1 or sum > target){
            return;
        }
        //recursive case
        //include the ith element
        if(sum+candidates[i] <= target){
            v.push_back(candidates[i]);
            solve(candidates,i,sum+candidates[i],target);
            v.pop_back();
        }
        //exclude the ith element
        solve(candidates,i+1,sum,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        solve(candidates,0,sum,target);
        return ans;    
    }
};