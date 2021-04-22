#include <bits/stdc++.h>
using namespace std;
int d[20001];
int m_visit[20001];
vector<pair<int, int> > connect[20001];

void bfs(int start){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	
	//���� ��� ť�� ���� 
	pq.push({0, start});
	
	while(!pq.empty()){
		//w : ������� ���������� �ش� ���� ������ ���� 
		int w = pq.top().first;
		int v = pq.top().second;
		
		pq.pop();
		
		//�̹� �ּ� ��θ� ������Ʈ�� ���(priority_queue�̱� ������ �տ��� ������ ���� �ּڰ�) 
		if(m_visit[v])
			continue;
		
		m_visit[v] = 1;
		d[v] = w;
		
		//�ش� �������� �ٸ� �������� ���� ť�� ���� 
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
