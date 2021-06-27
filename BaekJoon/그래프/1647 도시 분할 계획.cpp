#include<bits/stdc++.h>

using namespace std;

class Data{
	public:
		int x;
		int y;
		int c;
		
		Data(int x, int y, int c){
			this->x = x;
			this->y = y;
			this->c = c;
		}
		
		bool operator<(const Data &a) const{
			return this->c > a.c;
		}
};

int parent[100001];

int find(int a){
	if(parent[a] == a)
		return a;
	else
		return parent[a] = find(parent[a]);	
}

void unio(int a, int b){
	if(a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(int argc, char** argv)
{	
	ios_base::sync_with_stdio(false);
	
	int n, m;
	int res = 0;
	int max_cost = 0;
	priority_queue<Data> pq;
	
	cin>>n>>m;
	
	for(int i = 1; i <= n; i++)
		parent[i] = i;
	
	for(int i = 0; i < m; i++){
		int x, y, c;
		
		cin>>x>>y>>c;
		
		pq.push(Data(x,y,c));
	}
	
	
	//MST를 구한다. 
	while(!pq.empty()){
		int x = pq.top().x;
		int y = pq.top().y;
		int c = pq.top().c;
		
		pq.pop();
		
		int px = find(x);
		int py = find(y);
		
		if(px == py)
			continue;
		unio(py, px);
		
		//연결된 선중 가장 비용이 가장 비싼 비용을 저장해놓는다. 
		max_cost = max(max_cost, c);
		res += c;
	}
	
	//MST에서 가장 비싼 간선 하나를 지워서 두개의 마을로 나눈다. 
	res -= max_cost;
	
	cout<<res;	
}
