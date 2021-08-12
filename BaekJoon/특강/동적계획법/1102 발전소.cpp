#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define MAX 987654321
using namespace std;

int cache[1<<16][16];
int cost[16][16];
string plant;
int n;

int solve(int state, int remain){
	if(remain == 0)
		return 0;
	int& ret = cache[state][remain];
	
	if(ret != -1)
		return ret;
	
	ret = MAX;
	for(int i = 0; i < n; i++){
		if((state & (1<<i)))
			continue;
		int min_value = MAX;
		
		//현재 켜져있는 발전소중 가장 작은 발전소 값 찾기 
		for(int j = 0; j < n; j++){
			//자기자신 발전소거나 켜져있지 않은 발전소인 경우 
			if(j == i || !(state & (1<<j)))
				continue;
			
			min_value = min(min_value, cost[j][i]);
		}
		ret = min(ret, solve((state | (1<<i)), remain-1) + min_value);
	}
	return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>cost[i][j];
	cin>>plant;
	int on_cnt = 0;
	int state = 0;
	
	for(int i = 0; i < plant.size(); i++){
		if(plant[i] == 'Y'){
			state |= (1<<i);
			on_cnt++;
		}
	}
	
	int p;
	cin>>p;
	
	if(on_cnt >= p){
		cout<<"0";
		return 0;
	}
	
	else if(on_cnt == 0){
		cout<<"-1";
		return 0;
	}
	
	memset(cache, -1, sizeof(cache));
	
	int res = solve(state, p-on_cnt);
	
	cout<<res;
    return 0;
}
