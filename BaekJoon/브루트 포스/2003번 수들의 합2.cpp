#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n, m, res = 0;
	
	cin>>n>>m;
	 
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		//a[0] = ù��° ������ i��° ������ ��
		//a[1] = ��° ������ i��° ������ ��
		for(int j = 0; j <= i; j++){
			if(a[j] + x == m)
				res++;
			a[j] = a[j] + x;
		}
	}
	cout<<res;
	return 0;
}
