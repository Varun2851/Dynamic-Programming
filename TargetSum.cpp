#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(vector<int>& nums, int target, long long int sum, int idx, unordered_map<string, int>& memo) {
    if (idx == nums.size()) {
        if (sum == target) {
            return 1;
        }
        return 0;
    }

    string key = to_string(sum) +'@'+ to_string(idx);

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int count = 0;

    // add a '+' sign
    count += solve(nums, target, sum + nums[idx], idx + 1, memo);

    // add a '-' sign
    count += solve(nums, target, sum - nums[idx], idx + 1, memo);

    memo[key] = count;

    return count;
}

int main() {
    vector<int> nums = {42,24,30,14,38,27,12,29,43,42,5,18,0,1,12,44,45,50,21,47};
    int target = 38;
    long long int sum = 0;
    int idx = 0;
    unordered_map<string, int> memo;
    int count = solve(nums, target, sum, idx, memo);
    cout << count << endl;
    return 0;
}
