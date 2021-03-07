#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<pair<int, int> > costs;
int cache[1001][21];

int solve(int customer, int city){
	int& ret = cache[customer][city];
	int city_cost;
	
	//이미 탐색했으면 종료 
	if(ret != -1)
		return ret;
	
	//첫번째 호출이 아니라면 
	if(city != -1){
		//선택된 도시의 홍보인원을 전체 늘려야하는 고객수에서 차감 
		customer -= costs[city].second;
		//선택된 도시의 홍보 비용 저장 
	 	city_cost = costs[city].first;
	}
	//첫번째 호출의 경우 비용 0 
	else
		city_cost = 0;
	
	//늘려야하는 고객 할당량을 넘겼을때 
	if(customer <= 0)
		//해당 도시 홍보비용 리턴 
		return ret = city_cost;
	
	ret = 987654321;
	
	//n개의 도시 중 최소값을 ret에 저장 
	for(int i = 0; i < n; i++)
		ret = min(ret, solve(customer, i) + city_cost);
	
	return ret;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	
	cin>>c>>n;
	
	for(int i = 0; i < n; i++){
		int cost, customer;
		
		cin>>cost>>customer;
		
		costs.push_back({cost, customer});
	}
	
	memset(cache, -1, sizeof(cache));
	int res = solve(c, -1);
	
	cout<<res;
	return 0;
}
