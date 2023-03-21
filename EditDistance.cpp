#include<iostream>
using namespace std;
int dp[100][100];

int EditDistance(char *s1,char *s2,int i, int j){
	//base case
	if(i == 0) return dp[i][j] = j;
	if(j == 0) return  dp[i][j] =  i;

	//recursive case

	if(s1[i-1] != s2[j-1]){
		return 1+min(EditDistance(s1,s2,i-1,j),min(EditDistance(s1,s2,i-1,j-1),EditDistance(s1,s2,i,j-1)));
	}
	else{
		return EditDistance(s1,s2,i-1,j-1);
	}
}

int main(){
	char s1[] = "sunday";
	char s2[] = "saturday";

	cout<<EditDistance(s1,s2,strlen(s1),strlen(s2));

	return 0; 
}