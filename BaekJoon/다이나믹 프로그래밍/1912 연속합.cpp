#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int a[100001][3];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n, res;
	
	cin>>n;
	
	//0���ε��� : �������� �ִ� + �����ڽ��� ��
	//1���ε��� : �����ڽ��ǰ�
	//2�� �ε��� : 0  
	cin>>a[1][1];
	res = a[1][1];
	for(int i = 2; i <= n; i++){
		cin>>a[i][1];
		
		//0, 1, 2�� �ε������� �ִ��� ���� 
		int mx = max(a[i-1][0], a[i-1][1]);
		mx = max(mx, a[i-1][2]);
		//�ִ� + ���� �ڽ��ǰ� 
		a[i][0] = mx + a[i][1];
		
		//�� �� max���� ���� 
		mx = max(a[i][0], a[i][1]);
		//max�� ���� 
		if(mx > res)
			res = mx;
	}
	cout<<res;
	return 0;
}
