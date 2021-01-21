#include<iostream>
#include <bits/stdc++.h>
using namespace std;
char op[10];
int num[11];
int c[4];
int n;
int mx = -1000000001, mn = 1000000001;

void dfs(int x){
	if(x == n-1){
		int res = num[0];
		for(int i = 1; i < n; i++){
			if(op[i-1] == '+')
				res += num[i];
			else if(op[i-1] == '-')
				res -= num[i];
			else if(op[i-1] == '*')
				res *= num[i];
			else if(op[i-1] == '/' || num[i] != 0)
				res /= num[i];
			else
				continue;
		}
		if(mx < res)
			mx = res;
		if(mn > res)
			mn = res;
	}
	else{
		for(int i = 0; i < 4; i++){
			if(c[i] > 0){
				if(i == 0)
					op[x] = '+';
				else if(i == 1)
					op[x] = '-';
				else if(i == 2)
					op[x] = '*';
				else
					op[x] = '/';
				c[i]--;
				dfs(x+1);
				c[i]++;
				op[x] = 0;
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>num[i];
	for(int i = 0; i < 4; i++)
		cin>>c[i];
	
	dfs(0);
	cout<<mx<<endl<<mn;
	return 0;
}
