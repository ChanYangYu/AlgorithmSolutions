#include <bits/stdc++.h>
using namespace std;

int p[300][2]; 
int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	
	//n의 개수 입력 
	cin>>n;
	
	//첫번째 자리 = 연속합, 두번째 자리 연속합x 
	cin>>p[0][0];
	cin>>p[1][1];
	//2번 계단의 연속합   
	p[1][0] = p[1][1] + p[0][0];
	
	//3번 계단부터 DP시작 
	for(int i = 2; i < n; i++){
		int x;
		cin>>x;
		p[i][0] = p[i-1][1] + x;
		p[i][1] = max(p[i-2][0], p[i-2][1]) + x;
	}
	
	//둘 중 큰값을 출력 
	int res = max(p[n-1][0], p[n-1][1]);
	cout<<res;
	
	
    return 0;
}
