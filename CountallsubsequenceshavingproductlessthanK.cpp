#include<iostream>
using namespace std;
int cnt;
int n = 4;

void solve(int *arr,int product,int i,int k){
	//base case
	if(i == n){
		return;
	}

	//recursive case
	int newProduct = product*arr[i];
	if(newProduct<k){
		cnt++;
		solve(arr,newProduct,i+1,k);
	}

	//if we don't include ith ele
	solve(arr,product,i+1,k);
}

int main(){
	int arr[] = {4,8,7,2};
	
	int k = 10;

	solve(arr,1,0,k);
	cout<<cnt;
}