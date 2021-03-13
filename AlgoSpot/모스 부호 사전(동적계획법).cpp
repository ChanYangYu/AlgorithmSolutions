#include <bits/stdc++.h>
using namespace std;
const int M = 1000000000 + 100;
int bino[201][201];

//이항계수 구하기 
int calc_bino(){
	for(int i = 0; i <= 200; i++){
		bino[i][0] = 1;
		bino[i][i] = 1;
		
		for(int j = 1; j < i; j++){
			bino[i][j] = min(M, bino[i-1][j] + bino[i-1][j-1]);
		}
	}
}

//문제 해결 
string solve(int n, int m, int skip){
	//이미 n이 0이면 나머지는 모두 o이다. 
	if(n == 0) 
		return string(m, 'o');
	
	//-을 선택한 경우의 수 보다 skip이 작으면 -선택후 탐색 
	if(skip < bino[n+m-1][n-1])
		return "-" + solve(n-1, m, skip);
	//skip보다 작은 경우는 - 을 선택한 경우의 수는 고려할 필요없으므로 skip에서 제거 후 연산 
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
