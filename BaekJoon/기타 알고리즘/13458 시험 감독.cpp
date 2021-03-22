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
		
		//총감독관 배치 
		tmp = a[i] - b;
		num = 1;
		//총감독관으로 커버가 안되면 
		if(tmp > 0){
			//부감독관 추가배치 
			num += tmp / c;
			//나머지가 있는 경우 
			if(tmp % c != 0)
				num++;
		}
		
		res += num;
	}
	
	cout<<res;
	return 0;
}
