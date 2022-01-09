#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/*
	��ȭ��
	dp[n][k] = dp[n-1][k] + dp[n][k-1]
	
	-> k���� �̰� ���簪�� n-1�� ��� 1�� �߰��ϸ� �����Ѵ�.(�ߺ����� ���� �� �ֱ� ������ k���� �ϳ��� 1 ��ū�� �����ϸ� ��)
	-> k-1���� �̰� ���簪�� n�� ��� 0�� ������ �����Ѵ�. 
*/
int cache[5001][5001];

int solve(int cur, int cnt){
	if(cur == 0){
		return 1;
	}
	if(cnt == 1){
		return 1;
	}	
	
	int& ret = cache[cur][cnt];
	
	if(ret != -1){
		return ret;
	}
	
	return ret = (solve(cur-1, cnt) + solve(cur, cnt-1))%1000000000;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    
    cin>>n>>k;
    
    memset(cache, -1, sizeof(cache));
    cout<<solve(n, k);
	
    return 0;
}
