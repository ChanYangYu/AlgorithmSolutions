#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<int> s; 
int n;
vector<int> a;

void dfs(int i, int num){
	s.insert(num);
	if(i < n){
		dfs(i+1, num + a[i]);
		dfs(i+1, num);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	dfs(0,0);
	
	int i = 0;
	for(set<int>::iterator it = s.begin(); it != s.end(); it++){
		if(i != *it){
			cout<<i;
			return 0;
		}
		i++;
	}
	cout<<i;
}
