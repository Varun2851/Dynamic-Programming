#include<iostream>
using namespace std;

int solve(int arraylength,int indx,bool previous){
	//base case
	if(indx == arraylength){
		return 1;
	}
	//recursive case
	int ans = 0;
	//op1 = put 0 at the 0th index
	ans += solve(arraylength,indx+1,false);
	//op2 put 1 at the 0th index
	if(previous == false){
		ans += solve(arraylength,indx+1,true);
	}
	return ans;
}

int main(){
	int arraylength = 5;
	cout<<solve(arraylength,0,false);
	return 0;
}