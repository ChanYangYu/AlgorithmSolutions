#include <bits/stdc++.h>
using namespace std;
//���Ը� �������� ���ĵǴ� Data 
class Data{
	public:
		int m;
		int v;
		
		Data(int m, int v){
			this->m = m;
			this->v = v;
		}
		bool operator<(const Data & a) const{
			return this->m > a.m;
		}
};

//��ġ�� �������� ���ĵǴ� Data2 
class Data2{
	public:
		int m;
		int v;
		Data2(int m, int v){
			this->m = m;
			this->v = v;
		}
		bool operator<(const Data2 & a) const{
			return this->v < a.v;
		}
};
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	priority_queue<Data> pq1;
	priority_queue<Data2> pq2;
	vector<int> bags;
	int n, k;
	
	cin>>n>>k;
	
	for(int i = 0; i < n; i++){
		int m, v;
		
		cin>>m>>v;
		pq1.push(Data(m,v));
	}
	
	for(int i = 0; i < k; i++){
		int x;
		
		cin>>x;
		bags.push_back(x);
	}
	
	sort(bags.begin(), bags.end());
	
	long long res = 0;
	for(int i = 0; i < bags.size(); i++){
		int cur = bags[i];
		//���� ������ Ŀ���� �� �ִ� ������ pop�Ͽ� pq2�� ���� 
		while(!pq1.empty() && pq1.top().m <= cur){
			int m = pq1.top().m;
			int v = pq1.top().v;
			
			pq1.pop();
			
			pq2.push(Data2(m,v));
		}
		
		//pq2�� ������� �ʴٸ� ���� ��ġ�� �ִ� ���� ���� 
		if(!pq2.empty()){
			res += pq2.top().v;
			pq2.pop();
		}
	}
	
	cout<<res<<"\n";
    return 0;
}
