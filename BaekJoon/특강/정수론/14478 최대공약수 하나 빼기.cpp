#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int nums[1000001];
int left_gcd[1000002];
int right_gcd[1000002];

int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	
	int n;
	
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>nums[i];
	for(int i = 1; i <= n; i++){
		left_gcd[i] = gcd(left_gcd[i-1], nums[i]);
	}
	for(int i = n; i >= 1; i--){
		right_gcd[i] = gcd(right_gcd[i+1], nums[i]);
	}
	
	int res_k = -1;
	int res = left_gcd[n];
	
	for(int i = 1; i <= n; i++){
		int cur_gcd = gcd(left_gcd[i-1], right_gcd[i+1]);
		
		if(nums[i] % cur_gcd == 0)
			continue;
		if(res < cur_gcd){
			res_k = nums[i];
			res = cur_gcd;
		}
	}
	
	if(res_k == -1)
		cout<<"-1";
	else
		cout<<res<<" "<<res_k;
	return 0;
}
