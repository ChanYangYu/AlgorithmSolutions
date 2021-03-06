#include <bits/stdc++.h>

using namespace std;
int cache[101][101][101];
/* Ʋ���ڵ� cache[101][101] <- cache[d][r]
 �ݷ� d = 2, r = 1, n = 2 �� d = 2, r = 1, n = 1�� �ٸ� ���������
 ���� cache[d][r]�� �����ϰԵǾ� �߸� �����Ѵ�.
 ���� 3���� �迭�� cache[d][r][n]�� ����Ͽ��� �Ѵ�.
*/ 
int solve(int d, int r, int n){
	int& ret = cache[d][r][n];
	
	if(ret != -1)
		return ret;
	
	if(r == 0)
		return ret = 1;
	
	ret = 0;
	
	for(int i = 1; i <= r; i++){
		if(d != 0)
			ret += (solve(d+1, r - i, i) * (n + i - 1)) % 10000000;
		else
			ret += (solve(d+1, r - i, i)) % 10000000;
	}
	
	//�����÷ο� ����ó��!
	//Ʋ�� �ڵ� return ret % 10000000;
	//���� ���� �ڵ�� ret�� ������� �ʴ´�! 
	ret %= 10000000;
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	int t;
	int n;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n;
		
		memset(cache, -1, sizeof(cache));
		int res = solve(0, n, 0);
		
		cout<<res<<"\n";
	}
	return 0;
}
