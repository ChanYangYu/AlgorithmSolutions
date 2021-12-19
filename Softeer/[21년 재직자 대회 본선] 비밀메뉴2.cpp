#include <bits/stdc++.h>

using namespace std;

int cache[3001][3001][2];
vector<int> first;
vector<int> second;
int n, m, k;

int solve(int a, int b, int c){
	int& ret = cache[a][b][c];
	
	if(a == n || b == m){
		return ret = 0;
	}

	if(ret != -1){
		return ret;
	}

	ret = 0;

	if(c == 1){
		if(first[a] == second[b]){
			return ret = (solve(a+1, b+1, 1) + 1);
		}
		else{
			return ret = 0;
		}
	}
	else{
		ret = 0;
		for(int i = b; i < m; i++){
			if(first[a] == second[i]){
				ret = max(ret, solve(a+1, i+1, 1) + 1);
			}
		}
		ret = max(ret, solve(a+1, b, 0));
	}

}

int main(int argc, char** argv)
{
	cin>>n>>m>>k;

	for(int i = 0; i < n; i++){
		int x;

		cin>>x;
		first.push_back(x);
	}

	for(int i = 0; i < m; i++){
		int x;

		cin>>x;
		second.push_back(x);
	}

	memset(cache, -1, sizeof(cache));

	cout<<solve(0,0,0);
	return 0;
}
