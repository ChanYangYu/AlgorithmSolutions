
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > homes;
vector<pair<int, int> > chickens;
vector<int> ch;
int res = 987654321;
int n, m;

void solve(int cnt, int start){
	if(cnt == m){
		int sum = 0;
		for(int i = 0; i < homes.size(); i++){
			int mn = 987654321;
			int y1 = homes[i].first;
			int x1 = homes[i].second;
			
			for(int j = 0; j < chickens.size(); j++){
				if(ch[j] == 1){
					int y2 = chickens[j].first;
					int x2 = chickens[j].second;
					
					int dis = abs(y1 - y2) + abs(x1 - x2);
					mn = min(mn, dis); 
				}
			}
			
			//해당 집에서 최소 치킨 거리 구하기 
			sum += mn;
		}
		
		res = min(res, sum);
		return;		
	}
	
	for(int i = start; i < chickens.size(); i++){
		if(ch[i] == 0){
			ch[i] = 1;
			
			solve(cnt+1, i+1);
			
			ch[i] = 0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			
			cin>>x;
			
			if(x == 1)
				homes.push_back({i, j});
			else if(x == 2){
				chickens.push_back({i, j});
				ch.push_back(0);
			}
		}
	}
	
	//결과 출력
	
	solve(0, 0);
	
	cout<<res;

}

