#include <bits/stdc++.h>
using namespace std;
int d[20001];
int m_visit[20001];
vector<pair<int, int> > connect[20001];

void bfs(int start){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	//시작 노드 큐에 삽입 
	pq.push({0, start});
	
	while(!pq.empty()){
		//w : 현재까지 시작점에서 해당 정점 까지의 길이 
		int w = pq.top().first;
		int v = pq.top().second;
		
		pq.pop();
		
		//이미 최소 경로를 업데이트한 경우(priority_queue이기 때문에 앞에서 검토한 값이 최솟값) 
		if(m_visit[v])
			continue;
		
		m_visit[v] = 1;
		d[v] = w;
		
		//해당 정점에서 다른 정점까지 간선 큐에 저장 
		for(int i = 0; i < connect[v].size(); i++)
			pq.push({w + connect[v][i].second, connect[v][i].first});
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int e, v;
	int start;
	
	cin>>v>>e>>start;
	
	for(int i = 0; i < e; i++){
		int s, e, w;
		
		cin>>s>>e>>w;
		
		connect[s].push_back({e, w});
	}
	
	for(int i = 1; i <= v; i++)
		d[i] = 987654321;
	
	bfs(start);
	
	for(int i = 1; i <= v; i++){
		if(d[i] == 987654321)
			cout<<"INF\n";
		else
			cout<<d[i]<<"\n";
	}
	
    return 0;
}
