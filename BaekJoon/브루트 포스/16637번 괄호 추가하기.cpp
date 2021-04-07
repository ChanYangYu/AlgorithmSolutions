#include <bits/stdc++.h>
using namespace std;
char op[10];
int num[11];
char ex[20];
int n;
int mx = INT_MIN;

int calc(int a, int b, char o){
	if(o == '-')
		return a-b;
	else if(o == '+')
		return a+b;
	else if(o == '*')
		return a*b;
}

void solve(int idx, int nidx, int oidx){
	//���� ��� 
	if(idx >= n-1){
		//�� �ϳ��� ���� ��� 
		if(idx == n-1)
			num[nidx++] = ex[idx] - '0';
		
		//���� �ϳ��� ��� 
		if(nidx == 1){
			if(mx < num[0])
				mx = num[0];
			return;
		}
		//�ʱ갪 ��� 
		int res = calc(num[0], num[1], op[0]);
		
		//�� �� ��� 
		for(int i = 2; i < nidx; i++)
			res = calc(res, num[i], op[i-1]);
		if(mx < res)
			mx = res;
	}
	else{
		num[nidx] = ex[idx] - '0';
		op[oidx] = ex[idx+1];
		//�ȹ��� ��� 
		solve(idx+2, nidx+1, oidx+1);
		
		num[nidx] = calc(ex[idx] - '0', ex[idx+2] - '0', ex[idx+1]);
		
		//���� ���� ������ ���� �ִ� ��� 
		if(idx + 4 < n){
			op[oidx] = ex[idx+3];
			solve(idx+4, nidx+1, oidx+1);
		}
		//���� ���� ���̻� ������ ���� ��� 
		else
			solve(idx+4, nidx+1, oidx);
	}
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	cin>>n;
	cin>>ex;
	
	if(n == 1)
		cout<<ex;
	else{
		solve(0,0,0);
		cout<<mx;
	}
	return 0;
}
