#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, s;

//n/2 크기의 모든 부분수열의 합 계산 
void calc(vector<int> &arr, vector<int> &c, int idx, int state, int sum){
	if(idx == c.size())
		return;
	int choose_state = (state | (1<<idx));
	
	calc(arr, c, idx+1, choose_state, sum + c[idx]);
	arr[choose_state] = sum + c[idx];
	calc(arr, c, idx+1, state, sum);
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	
	int a_cnt = n/2;
	int b_cnt = n - a_cnt;
	vector<int> a((1<<a_cnt));
	vector<int> b((1<<b_cnt));
	
	vector<int> arr1(a_cnt);
	vector<int> arr2(b_cnt);
	
	for(int i = 0; i < a_cnt; i++)
		cin>>arr1[i];
	for(int i = a_cnt; i < n; i++)
		cin>>arr2[i-a_cnt];
	
	calc(a, arr1, 0, 0, 0);
	calc(b, arr2, 0, 0, 0);
	
	ll res = 0;
	
	//각각의 부분수열의 합 중 S값인 경우 체크 
	for(int i = 1; i < a.size(); i++)
		if(a[i] == s)
			res++;
	for(int i = 1; i < b.size(); i++)
		if(b[i] == s)
			res++;
	//b가 0인경우 맨뒤로 
	b[0] = 987654321;
	
	//b 정렬 
	sort(b.begin(), b.end());
	
	//a와 b의 합이 S인 모든 경우의 수 구함 
	for(int i = 1; i < a.size(); i++){
		int target = s - a[i];
		//target <= x < target 개수 res에 저장 
		res += upper_bound(b.begin(), b.end(), target) - lower_bound(b.begin(), b.end(), target);
	}
	
	cout<<res;
	return 0;
}
