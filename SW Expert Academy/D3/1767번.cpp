#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mp[12][12];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector<pair<int, int> > chips;
int res;
int res_cnt;
int n;

void solve(int idx, int cnt, int sum){
	if(chips.size() == idx){
		if(res_cnt < cnt){
			res_cnt = cnt;
			res = sum;
		}
		else if(res_cnt == cnt)
			res = min(res, sum);
		return;
	}
	
	int y = chips[idx].first;
	int x = chips[idx].second;
	
	for(int i = 0; i < 4; i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		bool check = true;
		int s = 0;
		
		//전선 연결 
		while(yy >= 0 && yy < n && xx >= 0 && xx < n){
			if(mp[yy][xx] != 0){
				check = false;
				break;
			}
			mp[yy][xx] = 2;
			s++;
			yy += dy[i];
			xx += dx[i];
		}
		
		//cout<<"dir : "<<i<<" s : "<<s<<"\n";
		//유망하면 체크 
		if(check)
			solve(idx+1, cnt+1, sum + s);
		
		yy = y + dy[i];
		xx = x +  dx[i];
		
		//전선 복구 
		for(int j = 0; j < s; j++){
			mp[yy][xx] = 0;
			yy += dy[i];
			xx += dx[i];
		}
	}
	
	//해당 칩 연결안할 경우 
	solve(idx+1, cnt, sum); 
	
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int test;
	
	cin>>test;
	for(int t = 1; t <= test; t++){
		cin>>n;
		chips.clear();
		res = 987654321;
		res_cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin>>mp[i][j];
				
				if(mp[i][j] == 1)
					if(i != 0 && j != 0 && i != n-1 && j != n-1)
						chips.push_back({i,j});
			}
		}
		
		solve(0, 0, 0);
		
		cout<<"#"<<t<<" "<<res<<"\n";
	}
	return 0;
}
