#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	vector<int> a;
	int n, b, c;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		
		a.push_back(x);
	}
	
	cin>>b>>c;
	
	long long res = 0;
	
	for(int i = 0; i < n; i++){
		int num;
		int tmp;
		
		//�Ѱ����� ��ġ 
		tmp = a[i] - b;
		num = 1;
		//�Ѱ��������� Ŀ���� �ȵǸ� 
		if(tmp > 0){
			//�ΰ����� �߰���ġ 
			num += tmp / c;
			//�������� �ִ� ��� 
			if(tmp % c != 0)
				num++;
		}
		
		res += num;
	}
	
	cout<<res;
	return 0;
}
