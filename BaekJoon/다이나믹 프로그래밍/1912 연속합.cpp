#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int a[100001][3];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n, res;
	
	cin>>n;
	
	//0번인덱스 : 이전값의 최댓값 + 현재자신의 값
	//1번인덱스 : 현재자신의값
	//2번 인덱스 : 0  
	cin>>a[1][1];
	res = a[1][1];
	for(int i = 2; i <= n; i++){
		cin>>a[i][1];
		
		//0, 1, 2번 인덱스에서 최댓값을 구함 
		int mx = max(a[i-1][0], a[i-1][1]);
		mx = max(mx, a[i-1][2]);
		//최댓값 + 현재 자신의값 
		a[i][0] = mx + a[i][1];
		
		//둘 중 max값을 구함 
		mx = max(a[i][0], a[i][1]);
		//max값 갱신 
		if(mx > res)
			res = mx;
	}
	cout<<res;
	return 0;
}
