#include <bits/stdc++.h>
#define ll long long
using namespace std;

int far_node;
vector<pair<int, int> > adj[100001];

//start노드부터 가장 먼 노드와의 거리를 리턴하고 전역변수 far_node를 갱신 
int get_dis(int start, int n){
	vector<int> check(n+1, 0);
	queue<pair<int, int> > q;
	
	far_node = -1;
	int dis = 0;
	
	check[start] = 1;
	q.push({start, 0});
	
	while(!q.empty()){
		int idx = q.front().first;
		int d = q.front().second;
		
		q.pop();
		
		if(dis < d){
			far_node = idx;
			dis = d;
		}
		
		for(int i = 0; i < adj[idx].size(); i++){
			int next = adj[idx][i].first;
			int len = adj[idx][i].second;
			
			if(check[next] == 0){
				check[next] = 1;
				q.push({next, d + len});
			}
		}
	}
	
	return dis;
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	
	cin>>n;
	
	for(int i = 1; i <= n; i++){
		int idx;
		int node, len;
		
		cin>>idx;
	
		cin>>node;
		while(node != -1){
			cin>>len;
			
			adj[idx].push_back({node, len});
			cin>>node;
		}
	} 
	
	//far_node 구하기 
	get_dis(1, n);
	//far_node에서 가장 먼 노드의 길이 출력 
	cout<<get_dis(far_node, n);

	return 0;
}


