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
		//ù��° �׺��� �����ױ��� ���� s�� �Ѵ� ���� 
		if(end == -1 && a[i] >= s)
			end = i;
	}
	
	//�κ������� ���°�� 
	if(end == -1)
		cout<<"0";
	else{	 
		//�������� ���������� ���� ���� 
		int res = end - start + 1;
		while(end <= n){
			//���� s�� �Ѵ� �ּҰ����� ���� �κ����� 
			while(a[end] - a[start] >= s)
				start++;
			//�κ����� ���� ���� 
			res = min(res, end - start + 1);
			end++;
		}
		cout<<res;
	}
	return 0;
}
