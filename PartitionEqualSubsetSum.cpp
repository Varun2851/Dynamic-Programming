#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums, int index, int sum, int target) {
    if (sum == target) {
        return true;
    }
    if (index >= nums.size() || sum > target) {
        return false;
    }
    return canPartition(nums, index + 1, sum + nums[index], target) || 
           canPartition(nums, index + 1, sum, target);
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 0 && canPartition(nums, 0, 0, sum/2)) {
        cout << "Can be partitioned into two subsets with equal sum\n";
    } else {
        cout << "Cannot be partitioned into two subsets with equal sum\n";
    }
    return 0;
}
