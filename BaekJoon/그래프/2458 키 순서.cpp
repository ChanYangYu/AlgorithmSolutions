#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

vector<int> taller[501];
vector<int> shorter[501];

int get_taller_cnt(int idx){
	queue<int> q;
	int ch[501] = {0,};
	
	q.push(idx);
	ch[idx] = 1;
	
	int cnt = 0;
	while(!q.empty()){
		int cur = q.front();
		
		q.pop();
		
		for(int i = 0; i < taller[cur].size(); i++){
			int next = taller[cur][i];
			if(ch[next] == 0){
				cnt++;
				q.push(next);
				ch[next] = 1;
			}
		}
	}
	
	return cnt;
}

int get_shorter_cnt(int idx){
	queue<int> q;
	int ch[501] = {0,};
	
	q.push(idx);
	ch[idx] = 1;
	
	int cnt = 0;
	while(!q.empty()){
		int cur = q.front();
		
		q.pop();
		
		for(int i = 0; i < shorter[cur].size(); i++){
			int next = shorter[cur][i];
			if(ch[next] == 0){
				cnt++;
				q.push(next);
				ch[next] = 1;
			}
		}
	}
	
	return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
    cin>>n>>m;
    
    while(m--){
    	int a, b;
    	
    	cin>>a>>b;
    	
    	taller[a].push_back(b);
    	shorter[b].push_back(a);
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++){
		int tmp = get_taller_cnt(i) + get_shorter_cnt(i);
		
		if(tmp == n-1)
			res++;
	}
    
    cout<<res;
   return 0;
}
