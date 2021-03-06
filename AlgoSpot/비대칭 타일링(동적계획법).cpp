#include <bits/stdc++.h>
/* Ǯ�� ����
 1. ���� ��ü�� ����� ���� ���ϴ� solve�Լ� ����
 2. n�� Ȧ�� �� ����� ��Ī�Ǵ� ����� �� ����
 3. n�� ¦�� �� ����� ��Ī�Ǵ� ����� �� ����
*/ 
using namespace std;
int cache[101];
int n;

int solve(int pos){
	int& ret = cache[pos];
	int mid = n / 2;
	int isOdd = n % 2;
	
	if(ret != -1)
		return ret;
	
	//Ȧ���� ��� ��Ī�Ǵ� ���� �߰����� ���� Ÿ���� �ݵ�� 1�϶��̴�. 
	if(isOdd && pos == mid)
		ret = -1;
	else	
		ret = 0;
	
	if(pos == n)
		return ret = 1;
		
	//¦���� ��� ��Ī�Ǵ� ���� ���� ��ġ�Ǵ� Ÿ���� �߰����� ������ ����̴�. 
	if(pos + 1 <= n){ 
		if(!isOdd && pos + 1 == mid)
			ret -= 1;
		ret += solve(pos+1);
	}
	if(pos + 2 <= n){
		if(!isOdd && (pos < mid && pos + 2 >= mid))
			ret -= 1;
		ret += solve(pos+2);
	}
	
	ret %= 1000000007;
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n;
		
		memset(cache, -1, sizeof(cache));
		int res = solve(0);
		
		cout<<res<<"\n";
	}
	return 0;
}
