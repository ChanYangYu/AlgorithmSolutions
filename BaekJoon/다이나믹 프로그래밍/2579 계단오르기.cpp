#include <bits/stdc++.h>
using namespace std;

int p[300][2]; 
int main(void){
	ios_base::sync_with_stdio(false);
	int n;
	
	//n�� ���� �Է� 
	cin>>n;
	
	//ù��° �ڸ� = ������, �ι�° �ڸ� ������x 
	cin>>p[0][0];
	cin>>p[1][1];
	//2�� ����� ������   
	p[1][0] = p[1][1] + p[0][0];
	
	//3�� ��ܺ��� DP���� 
	for(int i = 2; i < n; i++){
		int x;
		cin>>x;
		p[i][0] = p[i-1][1] + x;
		p[i][1] = max(p[i-2][0], p[i-2][1]) + x;
	}
	
	//�� �� ū���� ��� 
	int res = max(p[n-1][0], p[n-1][1]);
	cout<<res;
	
	
    return 0;
}
