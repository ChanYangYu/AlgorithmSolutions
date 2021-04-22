#include <bits/stdc++.h>
using namespace std;

int main(void){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	int t;
	long long MAX = 2000000000;
	
	cin>>t;
	
	for(int i = 0; i < t; i++){
		long long n, m;
		
		cin>>n>>m;
		
		//초기값(백분률) 
		double initial = (m * 100) / n;
		
		//20억번 초과 체크 
		if((((m + MAX) * 100) / (n + MAX)) - initial < 1){
			cout<<"-1\n";
			continue;
		}
		
		long long left = 0;
		long long right = MAX;
		
		//이분법으로 근사치 계산	
		while(left <= right){
			long long mid = (left + right) / 2;
				
			if((((m + mid) * 100) / (n + mid)) - initial >= 1)
				right = mid-1;
			else
				left = mid + 1;
		}
		//결과값 출력 
		cout<<left<<"\n";
	}

    return 0;
}
