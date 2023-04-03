#include<bits/stdc++.h>
#define  int long long int 
using namespace std;

int polyhash(string s){
	int mod = 1e9+7;
	int x = 31;
	int n = s.size();
	int power_p = 1; //31^0 = 1
	int hash = 0;

	for(int i = 0; i<n; i++){
		hash += (s[i]-'a'+1)*power_p;
		power_p *= x;

		hash %= mod;
		power_p %= mod;
	}
	return hash;
}

int32_t main(){
	string s = "abdggdgfgrfgr";
	cout<<polyhash(s);
	return 0;
}