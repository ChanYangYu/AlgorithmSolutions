#include <bits/stdc++.h>
using namespace std;
const int M = 1000000000 + 100;
int bino[201][201];

//���װ�� ���ϱ� 
int calc_bino(){
	for(int i = 0; i <= 200; i++){
		bino[i][0] = 1;
		bino[i][i] = 1;
		
		for(int j = 1; j < i; j++){
			bino[i][j] = min(M, bino[i-1][j] + bino[i-1][j-1]);
		}
	}
}

//���� �ذ� 
string solve(int n, int m, int skip){
	//�̹� n�� 0�̸� �������� ��� o�̴�. 
	if(n == 0) 
		return string(m, 'o');
	
	//-�� ������ ����� �� ���� skip�� ������ -������ Ž�� 
	if(skip < bino[n+m-1][n-1])
		return "-" + solve(n-1, m, skip);
	//skip���� ���� ���� - �� ������ ����� ���� ����� �ʿ�����Ƿ� skip���� ���� �� ���� 
	return "o" + solve(n, m-1, skip - bino[n+m-1][n-1]);
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int t;
	
	cin>>t;
	calc_bino();
	for(int i = 0; i < t; i++){
		int n, m, k;
		cin>>n>>m>>k;
		
		cout<<solve(n,m,k-1)<<"\n";
	}
	
	return 0;
}
