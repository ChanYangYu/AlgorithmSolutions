#include <bits/stdc++.h>
#define pii pair<int,int>

/*
	Ǯ��
	1. ������ �ִ°��� ��ġ�� ��ǥ�� ����. (y,x => y�� x ��ǻ�͸� ������ ������ ����)
	2. �����Ǳ���, y, x�� �켱����ť�� �ִ´�.
	3. Kruskal Algorithm�� ����Ͽ� �ּҽ���Ʈ���� ���Ѵ�.
	4. �ּҽ���Ʈ���� ��������ٸ� ���� ���� ���� ����Ѵ�.
	
	�����Ʈ
	-  m_find(i)�� �����༭ Ʈ���� �ֽ�ȭ�� �ȵǾ� Ʋ�Ⱦ���. 
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
