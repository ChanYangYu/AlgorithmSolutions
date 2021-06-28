#include<bits/stdc++.h>

using namespace std;
int a[1001];
int b[1001];
int a_cases[2000001];
int b_cases[2000001];

int main(int argc, char** argv)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int need;
	int n, m;
	
	cin>>need;
	cin>>n>>m;
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}
	
	//A피자 모두 선택한 경우 
	if(sum <= need)
		a_cases[sum]++;
	
	sum = 0;
	for(int i = 0; i < m; i++){
		cin>>b[i];
		sum += b[i];
	}
	
	//B피자 모두 선택한 경우 
	if(sum <= need)
		b_cases[sum]++;
	
	//A로 만들 수 있는 모든 피자조각의 경우의 수 a_cases에 저장 
	for(int i = 0; i < n; i++){
		sum = 0;
		
		//현재조각을 포함하는 모든 경우의 수 체크 
		for(int j = 0; j < n-1; j++){
			int idx = (i+j) % n;
			
			sum += a[idx];
			if(sum > need)
				break;
			a_cases[sum]++;
		}
	}
	
	//B로 만들 수 있는 모든 피자조각의 경우의 수 b_cases에 저장
	for(int i = 0; i < m; i++){
		sum = 0;
		for(int j = 0; j < m-1; j++){
			int idx = (i+j) % m;
			
			sum += b[idx];
			if(sum > need)
				break;
			b_cases[sum]++;
		}
	}
	
	long long res = 0;
	
	//각 각의 피자를 선택하지 않는 경우가 있을 수 있으므로 1로 초기화 
	a_cases[0] = 1;
	b_cases[0] = 1;
	for(int i = 0; i <= need; i++)
		res += a_cases[i] * b_cases[need-i];
	
	cout<<res;
}
