#include <bits/stdc++.h>
using namespace std;
int cache[100001][101];
int weight[101];
int value[101];
int n, k;

int solve(int cur, int idx){
	int& ret = cache[cur][idx];
	
	//�̹� ���� �ִ� ��� 
	if(ret != -1)
		return ret;
	
	//��� ���� ������ ��� 
	if(idx == n)
		return ret = 0;

	ret = 0;
	
	//���� �ʰ����������� ì��� ��� ���� 
	if(cur + weight[idx] <= k)
		ret = max(ret, solve(cur + weight[idx], idx +1) + value[idx]);
	//ì���� �ʴ� ��� ���� 
	ret = max(ret, solve(cur, idx + 1));
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	
	cin>>n>>k;
	
	for(int i = 0; i < n; i++)
		cin>>weight[i]>>value[i];
	
	memset(cache, -1, sizeof(cache));
	
	int res = solve(0, 0);
	
	cout<<res;
	return 0;
}
