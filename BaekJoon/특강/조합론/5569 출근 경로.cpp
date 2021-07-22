#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int cache[101][101][2][2];
int h, w;

ll solve(int y, int x, int d, int cnt){
	//cout<<y<<" "<<x<<" "<<d<<" "<<cnt<<"\n";
	if(y == h && x == w)
		return 1;
	int& ret = cache[y][x][d][cnt];
	
	if(ret != -1)
		return ret;
	ret = 0;
	
	if(y < h){
		if(d == 0)
			ret += solve(y+1, x, 0, 1);
		else if(cnt == 1)
			ret += solve(y+1, x, 0, 0);
	}
	
	if(x < w){
		if(d == 1)
			ret += solve(y, x+1, 1, 1);
		else if(cnt == 1)
			ret += solve(y, x+1, 1, 0);
	}
	
	ret %= 100000;
	return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	
	cin>>w>>h;
	
	memset(cache, -1, sizeof(cache));
	int res = (solve(2,1,0,1) + solve(1,2,1,1)) % 100000;
	cout<<res;
	return 0;
}
