#include <bits/stdc++.h>
#define ll long long
#define MAX INT_MAX
using namespace std;

int cache[501][501];
vector<pair<int, int> > mat;
int solve(int left, int right){
	if(left == right)
		return 0;
	int& ret = cache[left][right];
	
	if(ret != -1)
		return ret;
	
	for(int i = left; i <= right-1; i++){
		int tmp = solve(left, i) + solve(i+1, right) + mat[left].first * mat[i].second * mat[right].second;
		if(ret == -1)
			ret = tmp;
		else
			ret = min(ret, tmp);
	}
	
	return ret;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	
	cin>>n;
	while(n--){
		int r, c;
		
		cin>>r>>c;
		
		mat.push_back({r,c});
	}
	
	memset(cache, -1, sizeof(cache));
	cout<<solve(0, mat.size()-1);
	return 0;
}
