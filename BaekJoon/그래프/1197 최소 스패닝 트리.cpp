#include <bits/stdc++.h>
using namespace std;
class Edge{
	public:
		int a;
		int b;
		int c;
		Edge(int a, int b, int c){
			this->a = a;
			this->b = b;
			this->c = c;
		}
		bool operator<(const Edge&d) const{
			return this->c > d.c;
		}
};
int cycle[10001];

//union-find 함수 구현 
int m_find(int a){
	if(cycle[a] == a)
		return a;
	else
		return cycle[a] = m_find(cycle[a]);
}

void m_union(int a, int b){
	if(a < b)
		cycle[b] = a;
	else
		cycle[a] = b;
}

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int v,e;
	priority_queue<Edge> edges;
	
	cin>>v>>e;
	
	for(int i = 0; i < e; i++){
		int a, b, c;
		
		cin>>a>>b>>c;
		
		edges.push(Edge(a,b,c));
	}
	
	//cycle 배열 초기화 
	for(int i = 1; i <= v; i++)
		cycle[i] = i;
	
	int res = 0;
	//최소 edge부터 연결 
	while(!edges.empty()){
		
		int a = edges.top().a;
		int b = edges.top().b;
		int c = edges.top().c;
		edges.pop();
		
		int parent_a = m_find(a);
		int parent_b = m_find(b);
		
		//사이클을 만들지 않는다면 edge연결 
		if(parent_a != parent_b){
			m_union(parent_a, parent_b);
			res += c;
		}
	}
	
	cout<<res;
    return 0;
}
