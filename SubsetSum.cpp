#include<iostream>
using namespace std;

int solve(int *arr,int indx,int sum){
	//base case
	if(indx == -1){
		return (sum == 0);
	}
	//recursive case
	//include the ith element
	bool ans = false;
	if(sum>=arr[indx]){
		ans |= solve(arr,indx-1,sum-arr[indx]);
	}
	//exclude the ith element
	ans |= solve(arr,indx-1,sum);
	return ans;
}

//other way implementation

int solve1(int *arr,int n,int indx,int sum,int targetSum){
	//base case
	if(indx == n){
		return (targetSum == sum);
	}

	//recursive case
	bool ans = false;
	if(sum>=arr[indx]){
		ans |= solve1(arr,n,indx+1,sum,targetSum+arr[indx]);
	}
	ans |= solve1(arr,n,indx+1,sum,targetSum);

	return ans;
}

int main(){

	int arr[] = {2,7,4,5,19};
	int n = sizeof(arr)/sizeof(int);
	int sum;
	cin>>sum;
	cout<<solve(arr,n-1,sum);
	cout<<solve1(arr,n,0,sum,0);
	return 0;
}