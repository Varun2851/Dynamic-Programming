#include<bits/stdc++.h>
using namespace std;

string longestDuplicateSubstring(string s, int n){
	unordered_set<string>st;
	string result;

	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			string substring = s.substr(i,j-i+1);
			if(st.count(substring) and substring.size() > result.size()){
				result = substring;
			}
			st.insert(substring);
		}
	}
	return result;
}

int main(){
	string s = "banana";
	int n = s.size();
	cout<<longestDuplicateSubstring(s,n);
	return 0;
}

