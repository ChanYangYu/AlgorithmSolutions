#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int ch[9];
int h[9];
vector<int> res;

void dfs(int n, int idx){
	if(res.size() > 0)
		return;
	if(n == 2){
		int sum = 0;
		for(int i = 0; i < 9; i++)
			if(ch[i] == 0)
				sum += h[i];
		if(sum == 100){
			for(int i = 0; i < 9; i++)
				if(ch[i] == 0)
					res.push_back(h[i]);
		}
		return;
	}
	else{
		for(int i = idx; i < 9; i++){
			ch[i] = 1;
			dfs(n+1,i+1);
			ch[i] = 0;
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
		
	for(int i = 0; i < 9; i++)
		cin>>h[i];
	
	dfs(0,0);
	
	sort(res.begin(), res.end());
	
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<endl;
	return 0;
}
