#include <bits/stdc++.h>
#define pii pair<int,int>

/*
	풀이
	1. 랜선이 있는곳의 위치를 좌표로 본다. (y,x => y와 x 컴퓨터를 연결한 랜선의 길이)
	2. 랜선의길이, y, x를 우선순위큐에 넣는다.
	3. Kruskal Algorithm을 사용하여 최소신장트리를 구한다.
	4. 최소신장트리가 만들어졌다면 남은 랜선 길이 출력한다.
	
	오답노트
	-  m_find(i)을 안해줘서 트리의 최신화가 안되어 틀렸었다. 
*/


using namespace std;

class Data{
	public:
		int l;
		int y;
		int x;
		
		Data(int l, int y, int x){
			this->l = l;
			this->y = y;
			this->x = x;
		}
		
		bool operator<(const Data& a) const{
			return this->l > a.l;
		}
};

int parent[51];

int char_to_int(char c) {
	if(c >= 'a' && c <= 'z')
		return c - 'a' + 1;
	else
		return c - 'A' + 27;
}

int m_find(int a){
	if(parent[a] == a)
		return a;
	else
		return parent[a] = m_find(parent[a]);
}

void m_union(int a, int b){
	if(a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   	int n;
   	priority_queue<Data> pq;
   	
   	cin>>n;
   	
   	for(int i = 1; i <= n; i++){
   		parent[i] = i;
   		for(int j = 1; j <= n; j++){
   			char c;
			int l;
			
			cin>>c;
			
			if(c == '0')
				continue;
			l = char_to_int(c);
			pq.push(Data(l, i, j));
		}
	}
	
	int res = 0;
	
	while(!pq.empty()){
		Data lan = pq.top();
		
		pq.pop();
		
		int py = m_find(lan.y);
		int px = m_find(lan.x);
			
		if(py == px)
			res += lan.l;
		else
			m_union(py, px);
	}
	
	for(int i = 1; i <= n; i++){
		m_find(i);
		if(parent[i] != 1){
			cout<<"-1\n";
			return 0;
		}
	}
	
	cout<<res<<"\n";
    return 0;
}
