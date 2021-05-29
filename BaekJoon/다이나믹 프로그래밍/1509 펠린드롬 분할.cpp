#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int cache[2501][2501];
vector<int> next_p[2501];

int solve(int left, int right){
	//�� �ڸ� ���� ��� 
	if(left == right)
		return 1;
	//��� �ڸ��� �̹� ���õ� ��� 
	else if(left > right)
		return 0;
	
	int& ret = cache[left][right];
	
	if(ret != -1)
		return ret;
	
	//���� ��ġ���� ���� �� �ִ� �縰��� ��ġ�� ��� Ž���غ���. 
	for(int i = 0; i < next_p[left].size(); i++){
		//tmp = (�縰��� ������ ��ġ + 1) ~ (�� ���ڿ�) �� �ּڰ� + 1  
		int tmp = solve(next_p[left][i]+1, right) + 1;
		if(ret == -1)
			ret = tmp;
		else
			ret = min(ret, tmp);
	}
	
	return ret;
}
void get_next_pel(int idx){
	int lptr = idx-1;
	int rptr = idx+1;
	int n = a.size();
	
	//���ڸ��� ��� �縰���
	next_p[idx].push_back(idx); 
	
	//���� ��ġ���� Ȧ���� �縰��� üũ 
	while(lptr >= 0 && rptr <= n-1){
		if(a[lptr] != a[rptr])
			break;
		next_p[lptr--].push_back(rptr++);	
	}
	
	//¦�� �� �縰��� üũ 
	lptr = idx-1;
	rptr = idx;
		
	while(lptr >= 0 && rptr <= n-1){
		if(a[lptr] != a[rptr])
			break;
		next_p[lptr--].push_back(rptr++);
	}
} 

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int m;
		
	cin>>a;
	for(int i = 0; i < a.size(); i++)
		get_next_pel(i);
	
	memset(cache, -1, sizeof(cache));
	cout<<solve(0, a.size()-1);
	return 0;
}
