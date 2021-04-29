#include <bits/stdc++.h>
using namespace std;
//무게를 기준으로 정렬되는 Data 
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

//가치를 기준으로 정렬되는 Data2 
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
		//가방 무겍가 커버할 수 있는 보석을 pop하여 pq2에 저장 
		while(!pq1.empty() && pq1.top().m <= cur){
			int m = pq1.top().m;
			int v = pq1.top().v;
			
			pq1.pop();
			
			pq2.push(Data2(m,v));
		}
		
		//pq2가 비어있지 않다면 가장 가치가 있는 보석 선택 
		if(!pq2.empty()){
			res += pq2.top().v;
			pq2.pop();
		}
	}
	
	cout<<res<<"\n";
    return 0;
}
