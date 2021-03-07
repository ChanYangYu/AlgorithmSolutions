#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<pair<int, int> > costs;
int cache[1001][21];

int solve(int customer, int city){
	int& ret = cache[customer][city];
	int city_cost;
	
	//�̹� Ž�������� ���� 
	if(ret != -1)
		return ret;
	
	//ù��° ȣ���� �ƴ϶�� 
	if(city != -1){
		//���õ� ������ ȫ���ο��� ��ü �÷����ϴ� �������� ���� 
		customer -= costs[city].second;
		//���õ� ������ ȫ�� ��� ���� 
	 	city_cost = costs[city].first;
	}
	//ù��° ȣ���� ��� ��� 0 
	else
		city_cost = 0;
	
	//�÷����ϴ� �� �Ҵ緮�� �Ѱ����� 
	if(customer <= 0)
		//�ش� ���� ȫ����� ���� 
		return ret = city_cost;
	
	ret = 987654321;
	
	//n���� ���� �� �ּҰ��� ret�� ���� 
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
