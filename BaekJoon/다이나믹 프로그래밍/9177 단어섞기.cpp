#include <bits/stdc++.h>
using namespace std;
string first, second, target;
int len;
int cache[201][201];

int solve(int f, int s, int t){
	int& ret = cache[f][s];
	
	//�湮���� ���� 
	if(ret != -1)
		return ret;
	
	//target�� �������� ��� 
	if(t == len)
		return ret = 1;
	
	ret = 0;
	//���� target[t]�� ù��° ���ڿ�[f]�� ��ġ�ϸ� 
	if(first[f] == target[t])
		ret = solve(f+1, s, t+1);
	//���� target[t]�� �ι�° ���ڿ�[s]�� ��ġ�ϸ� 
	if(second[s] == target[t])
		//�������� 1�� ������� �� �����Ƿ� max�� ����� 
		ret = max(ret, solve(f, s+1, t+1));
	
	return ret;
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>first>>second>>target;
		memset(cache, -1, sizeof(cache));
		len = first.size() + second.size();
		int res = solve(0, 0, 0);
		
		if(res)
			cout<<"Data set "<<i+1<<": yes\n";
		else
			cout<<"Data set "<<i+1<<": no\n";
	}
	return 0;
}
