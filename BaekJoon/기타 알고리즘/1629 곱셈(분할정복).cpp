#include <bits/stdc++.h>
using namespace std;
long long pows[100001];

long long my_pows(long long a, long long b, long long c){
	if(b == 0)
		return 1;
	else{
		long long tmp = my_pows(a, b / 2, c);
		
		if(b % 2 == 0)
			return (tmp * tmp) % c;
		else
			return ((tmp * tmp) % c * a) % c; 
	}
	
}
int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	long long a, b, c;
	long long mod;
	cin>>a>>b>>c;
	
	//��ⷯ ���갪 ����(������) 
	mod = a % c;
	
	//divide-conquer
	//cout<<my_pows(mod, b, c);
	
	//�ʱ갪 ���� 
	pows[0] = 1;
	//a�� 1 ~ 100000���� ���� �� ���� 
	for(int i = 1; i <= 100000; i++)
		pows[i] = (pows[i-1] * mod) % c;
	
	//100000������ ������ ��� 
	if(b <= 100000)
		cout<<pows[b];
	else{
		//�ʱ갪 
		long long res = 1;
		while(b >= 100000){
			b -= 100000;
			//100000�� ������ �� 
			res = (res * pows[100000]) % c;
		}
		
		//100000���� b ������ ���� 
		res = (res * pows[b]) % c;
		
		cout<<res;
	}
    return 0;
}
