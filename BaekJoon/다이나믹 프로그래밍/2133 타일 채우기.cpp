#include <bits/stdc++.h>
using namespace std;
int cache[31][16][3];
int n;

int solve(int pos, int jmp, int cases){
	int& ret = cache[pos][jmp][cases];
	
	//�̹� ���� ��� 
	if(ret != -1)
		return ret;
	
	//�� ä���� 
	if(pos == n)
		return ret = 1;
	
	ret = 0;
	//2 ~ 30�� ä��� Ÿ���� ��� Ž�� 
	for(int i = 1; i <= 15; i++){
		//Ÿ���� ä�� �� �ִ� ��� 
		if(pos + (2*i) <= n){
			//��, �Ʒ� �ٲ� �ΰ��� ��� Ž�� 
			ret += solve(pos + (2*i), i, 0);
			ret += solve(pos + (2*i), i, 1);
			//ũ�Ⱑ 2�� ���� 2*1 3�� �ΰ�� üũ 
			if(i == 1)
				ret += solve(pos + (2*i), i, 2);
		}
		else
			break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	
	cin>>n;
	memset(cache, -1, sizeof(cache));
	int res = solve(0, 0, 0);
	
	cout<<res;
	return 0;
}
