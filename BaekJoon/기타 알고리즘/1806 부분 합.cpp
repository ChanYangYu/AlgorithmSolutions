#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100001];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n,s;
	cin>>n>>s;
	
	int start = 1;
	int end = -1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		a[i] += a[i-1];
		//첫번째 항부터 현재항까지 합이 s를 넘는 지점 
		if(end == -1 && a[i] >= s)
			end = i;
	}
	
	//부분집합이 없는경우 
	if(end == -1)
		cout<<"0";
	else{	 
		//시작점과 끝점사이의 원소 갯수 
		int res = end - start + 1;
		while(end <= n){
			//합이 s를 넘는 최소개수를 갖는 부분집합 
			while(a[end] - a[start] >= s)
				start++;
			//부분집합 개수 갱신 
			res = min(res, end - start + 1);
			end++;
		}
		cout<<res;
	}
	return 0;
}
