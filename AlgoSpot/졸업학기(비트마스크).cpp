#include <bits/stdc++.h>
using namespace std;
int n, k, l, m;
int preq[12];
vector<int> c[11];
int cache[1<<12][11];

//state : 현재 이수상태, cur : 학기, r : 남은 과목 
int solve(int state, int cur, int r){
	if(r <= 0)
		return 0;
	
	if(cur == m)
		return 987654321;
	
	int& ret = cache[state][cur];
	
	if(ret != -1)
		return ret;
		
	ret = 987654321;
	vector<int> poss;
	int can_take = 0;
	//현재 학기에서 들을 수 있는 과목 추출 
	for(int i = 0; i < c[cur].size(); i++){
		int s = c[cur][i];
		
		//아직 수강하지 않았고, 이수과목을 만족하는 경우 
		if(!(state & (1<<s)) && (state & preq[s]) == preq[s]){
			poss.push_back(s);
			can_take |= (1<<s);
		}
	}
	
//	for(int take = can_take; take > 0; take = ((take-1) & can_take)){
//		int cnt = 0;
//		
//		for(int i = 0; i < 12; i++)
//			if((take & (1<<i)))
//				cnt++;
//		if(cnt > l)
//			continue;
//		
//		ret = min(ret, solve((state | take), cur+1, r-cnt) + 1);
//	}
	int p = poss.size();
	
	//들을 수 있는 과목이 최대 수강과목을 초과한 경우 
	if(p > l){
		vector<int> ch(p, 0);
		
		for(int i = 0; i < l; i++)
			ch[i] = 1;
		
		do{
			int next_state = state;
			for(int i = 0; i < p; i++)
				if(ch[i])
					next_state |= (1<<poss[i]);
			
			ret = min(ret, solve(next_state, cur+1, r-l) + 1);
		}while(next_permutation(ch.begin(), ch.end()));
	}
	//들을 수 있는과목이 하나이상인 경우 
	else{
		//과목 이수
		int take = 0;
		for(int i = 0; i < p; i++)
			take |= (1<<poss[i]);
		ret = min(ret, solve((state | take), cur+1, r-p) + 1);
	}
	//휴학하는 경우 
	ret = min(ret, solve(state, cur+1, r));
	
	return ret;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int z = 0; z < t; z++){
		cin>>n>>k>>m>>l;
		for(int i = 0; i < n; i++){
			int p;
			cin>>p;
			
			preq[i] = 0;
			for(int j = 0; j < p; j++){
				int s;
				
				cin>>s;
				
				preq[i] |= (1<<s);
			}
		}
		
		for(int i = 0; i < m; i++){
			int cnt;
			
			cin>>cnt;
			c[i].clear();
			for(int j = 0; j < cnt; j++){
				int s;
				
				cin>>s;
				
				c[i].push_back(s);
			}
		}
		
		memset(cache, -1, sizeof(cache));
		int res = solve(0, 0, k);
		
		if(res != 987654321)
			cout<<res<<"\n";
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
