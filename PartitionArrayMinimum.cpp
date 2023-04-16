//Partition a set into two subsets such that the difference of subset sums is minimum

#include <iostream>
#include <cmath>
using namespace std;

int subset_sum_difference(int arr[], int n, int sum1, int sum2, int i) {
    // base case
    if (i == n) {
        return abs(sum1 - sum2);
    }

    // recursive case
    // include the current element in the first subset
    int diff1 = subset_sum_difference(arr, n, sum1+arr[i], sum2, i+1);
    // include the current element in the second subset
    int diff2 = subset_sum_difference(arr, n, sum1, sum2+arr[i], i+1);

    return min(diff1, diff2);
}

int main() {
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum1 = 0, sum2 = 0, i = 0;
    int min_diff = subset_sum_difference(arr, n, sum1, sum2, i);
    cout << "Minimum difference between subset sums is " << min_diff << endl;
    return 0;
}
