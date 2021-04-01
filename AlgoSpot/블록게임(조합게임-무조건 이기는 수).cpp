#include <bits/stdc++.h>
char cache[1<<25];
char mp[5][5];
int dy[8] = {-1, -1, 1, 1, 1, 0};
int dx[8] = {1, -1, -1, 1, 0, 1};
using namespace std;
int solve(int state){
	char& ret = cache[state];
	
	if(ret != -1)
		return ret;
	
	ret = 0;
	int cnt = 0;
	//최선을 다하는 경우!
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(mp[i][j] == '.'){
				// l자 
				for(int k = 0; k < 4; k++){
					int yy = i + dy[k];
					int xx = j + dx[k];
					if(yy >= 5 || yy < 0 || xx >= 5 || xx < 0)
						continue;
					if(mp[yy][j] != '.' || mp[i][xx] != '.')
						continue;
					int p = (5 * i) + j;
					int p2 = (5 * yy) + j;
					int p3 = (5 * i) + xx;
					
					state += (1<<p);
					mp[i][j] = '#';
					state += (1<<p2);
					mp[yy][j] = '#';
					state += (1<<p3);
					mp[i][xx] = '#';
					
					cnt++;
					int tmp = solve(state);
					
					state -= (1<<p);
					mp[i][j] = '.';
					state -= (1<<p2); 
					mp[yy][j] = '.';
					state -= (1<<p3);
					mp[i][xx] = '.';
					
					//다음 차례에서의 모든 경로가 다 지는 경우
					if(!tmp){
						ret = 1;
						return ret;
					}
				}
				
				//I자 
				for(int k = 4; k < 6; k++){
					int yy = i + dy[k];
					int xx = j + dx[k];
					
					if(yy >= 5 || yy < 0 || xx >= 5 || xx < 0)
						continue;
					if(mp[yy][xx] == '.'){
						int p = (5 * i) + j;
						int p2 = (5 * yy) + xx;
						
						state += (1<<p);
						mp[i][j] = '#';
						state += (1<<p2);
						mp[yy][xx] = '#';
						
						cnt++;
						int tmp = solve(state);
						state -= (1<<p);
						mp[i][j] = '.';
						state -= (1<<p2);
						mp[yy][xx] = '.';
						
						//다음 차례에서의 모든 경로가 다 지는 경우
						if(!tmp){
							ret = 1;
							return ret;
						}
					}
				}
			}
		}
	}
	
	//모든 경우에서 이길 수 없으면 0리턴 
	return ret;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int state = 0;
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				cin>>mp[i][j];
				int p = (5 * i) + j;
				if(mp[i][j] == '#')
					state += (1<<p);
			}
		}
		memset(cache, -1, sizeof(cache));
		
		if(solve(state))
			cout<<"WINNING\n";
		else
			cout<<"LOSING\n";
	
	}
	return 0;
}
